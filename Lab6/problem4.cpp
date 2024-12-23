#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the rod length: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices for each length (1 to " << n << "):\n";
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    vector<int> prev(n+1,-1);
    for(int N=0;N<=n;N++){
        prev[N]=price[0]*N;
    }
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
            int notTake=prev[N];
            int take=INT_MIN;
            int rodLength=ind+1;
            if(rodLength<=N){
                take=price[ind]+prev[N-rodLength];
            }
            prev[N]=max(take,notTake);
        }
    }
    int maxRevenue = prev[n];
    cout << "The maximum obtainable revenue is: " << maxRevenue << endl;

    return 0;
}