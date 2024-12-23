
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;
    vector<int> prev(t.size()+1,0),cur(t.size()+1,0);

    for(int i=1;i<s.size()+1;i++){
        for(int j=1;j<t.size()+1;j++){
            if(s[i-1]==t[j-1]){
                cur[j]=1+prev[j-1];
            }else{
                cur[j]=max(prev[j],cur[j-1]);
            }
        }
        prev=cur;
    }

    int len = prev[t.size()];
    cout << "The length of the longest common subsequence is: " << len << endl;

    return 0;
}