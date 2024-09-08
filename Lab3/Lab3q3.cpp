#include <bits/stdc++.h>

using namespace std;
//partition
int partition(vector<int>& arr, int l, int h, int pvtIdx) {
    int pvtVal = arr[pvtIdx];
    swap(arr[pvtIdx], arr[h]);  
    int idx = l;
    
    for (int i = l; i < h; i++) {
        if (arr[i] < pvtVal) {
            swap(arr[i], arr[idx]);
            idx++;
        }
    }
    swap(arr[idx], arr[h]); 
    return idx;
}

// median of 5
int median5(vector<int>& arr, int low, int n) {
    sort(arr.begin() + low, arr.begin() + low + n);  
    return arr[low + n / 2];  
}

// recurssion to select k-th smallest element
int select(vector<int>& arr, int low, int high, int k);

// median of medians
int medianOfMedians(vector<int>& arr, int low, int high) {
    int n = high - low + 1;
    if (n <= 5) {
        return median5(arr, low, n);
    }

    vector<int> medians((n + 4) / 5); 
    for (int i = 0; i < medians.size(); i++) {
        int grpstart = low + i * 5;
        int grpsz = min(5, n - i * 5);
        medians[i] = median5(arr, grpstart, grpsz);
    }
    return select(medians, 0, medians.size() - 1, medians.size() / 2);
}
// k-th smallest element
int select(vector<int>& arr, int l, int h, int k) {
    if (l == h) {
        return arr[l];
    }

    int pivot = medianOfMedians(arr, l, h);

    int pvtIdx = partition(arr, l, h, find(arr.begin() + l, arr.begin() + h + 1, pivot) - arr.begin());

    int rank = pvtIdx - l;

    if (k == rank) {
        return arr[pvtIdx];
    } else if (k < rank) {
        return select(arr, l, pvtIdx - 1, k);  
    } else {
        return select(arr, pvtIdx + 1, h, k - rank - 1); 
    }
}

// Median of Medians
int medianOfArray(vector<int>& arr) {
    int n = arr.size();
    if (n % 2 == 1) {
        return select(arr, 0, n - 1, n / 2);  
    } else {
        int left_median = select(arr, 0, n - 1, n / 2 - 1);
        int right_median = select(arr, 0, n - 1, n / 2);
        return (left_median + right_median) / 2;  
    }
}

// Example usage
int main() {
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26};
    cout << "Median: " << medianOfArray(arr) << endl;
    return 0;
}
