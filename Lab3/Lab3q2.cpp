#include<bits/stdc++.h>

using namespace std;

// Partition function
int partition(vector<int>& arr, int l, int r) {
    int pivotIndex = l + rand() % (r - l + 1);
    int pivotValue = arr[pivotIndex];

    swap(arr[pivotIndex], arr[r]);
    int idx = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[idx], arr[r]);
    return idx;
}

// Quickselect 
int quickselect(vector<int>& arr, int l, int r, int k) {
    if (l == r) {
        return arr[l]; 
    }
    int pivot = partition(arr, l, r);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickselect(arr, l, pivot - 1, k); 
    } else {
        return quickselect(arr, pivot + 1, r, k);
    }
}

int main() {
    vector<int> arr = {7, 2, 1, 10, 5, 8, 3, 6};
    int k = 4;
    int result = quickselect(arr,0,arr.size()-1, k-1);
    cout << "The " << k << "th smallest element is: " << result << std::endl;

    return 0;
}
