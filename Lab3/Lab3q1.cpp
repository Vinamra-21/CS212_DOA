#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int maxi=INT_MIN;
    int mini=INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i]>maxi){
            maxi=arr[i];
        }
        if(arr[i]<mini){
            mini=arr[i];
        }
    }
    cout<<"The maximum element in the array is: "<<maxi<<endl;
    cout<<"The minimum element in the array is: "<<mini<<endl;

    return 0;
}