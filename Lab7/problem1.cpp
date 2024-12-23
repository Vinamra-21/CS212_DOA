#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualGraph[u][v] > 0) {  
                parent[v] = u;
                visited[v] = true;
                q.push(v);
                if (v == sink) return true;  
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> residualGraph = graph; 
    vector<int> parent(n);

    int maxFlow = 0;

    while (bfs(residualGraph, source, sink, parent)) {
        
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

    cout << "The maximum possible flow is: " << fordFulkerson(graph, source, sink) << endl;

    return 0;
}




// Enter the number of vertices: 6
// Enter the adjacency matrix (capacity of each edge):
// 0 16 13 0 0 0
// 0 0 10 12 0 0
// 0 4 0 0 14 0
// 0 0 9 0 0 20
// 0 0 0 7 0 4
// 0 0 0 0 0 0
// The maximum possible flow is: 23