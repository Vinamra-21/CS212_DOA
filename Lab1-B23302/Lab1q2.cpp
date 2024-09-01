#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

//merge-sort
void merge(int* arr, int s, int e, int mid) {
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1 + 1];
    int *second = new int[len2 + 1];
    
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }
    first[len1] = INT_MAX;
    
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }
    second[len2] = INT_MAX;
    
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;
    
    while (index1 < len1 || index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    
    delete[] first;
    delete[] second;
}

void mergeSort(int* arr, int s, int e) {
    if (s >= e) return;
    
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e, mid);
}

// Test sorting performance for a given case
void testSortingPerformance(const vector<int>& data, const string& caseName, int arraySize) {
    int* arr = new int[arraySize];
    copy(data.begin(), data.end(), arr);
    
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arraySize - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
    
    ofstream file("sorting_performanceq2.csv", ios::app);
    file << caseName << "," << arraySize << "," << duration.count() << "\n";
    file.close();
    
    delete[] arr;
}

int main() {
    ofstream file("sorting_performanceq2.csv");
    file << "Case,Array Size,Time (seconds)\n"; // CSV header
    file.close();

    vector<int> randomData, sortedData, reverseData, duplicateData;

    // Test for different array sizes
    for (int size : {100, 1000, 10000}) {
        randomData.clear();
        sortedData.clear();
        reverseData.clear();
        duplicateData.clear();

        for (int i = 0; i < size; ++i) {
            int value = rand() % size;
            randomData.push_back(value);
            sortedData.push_back(i);
            reverseData.push_back(size - i);
            duplicateData.push_back(42);  
        }

        // Test each case
        testSortingPerformance(randomData, "Random", size);
        testSortingPerformance(sortedData, "Sorted", size);
        testSortingPerformance(reverseData, "Reverse-Sorted", size);
        testSortingPerformance(duplicateData, "Duplicate", size);
    }

    cout << "Performance testing complete. Results written to sorting_performanceq2.csv" << endl;

    return 0;
}
