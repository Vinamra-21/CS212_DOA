#include <iostream>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

bool dfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent, vector<bool>& visited) {
    visited[source] = true;

    if (source == sink) return true;

    for (int v = 0; v < residualGraph.size(); ++v) {

        if (!visited[v] && residualGraph[source][v] > 0) {
            parent[v] = source;  
            if (dfs(residualGraph, v, sink, parent, visited)) {
                return true; 
            }
        }
    }

    return false; 
}

int fordFulkersonDFS(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph = graph;  
    vector<int> parent(n);  
    int maxFlow = 0;

    while (true) {
        vector<bool> visited(n, false);  
        if (!dfs(residualGraph, source, sink, parent, visited)) break;  

        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int n;  
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix (capacity of each edge):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int source = 0;  
    int sink = n - 1;  

    cout << "The maximum possible flow is: " << fordFulkersonDFS(graph, source, sink) << endl;

    return 0;
}

