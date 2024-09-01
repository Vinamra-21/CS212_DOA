#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

//quick-sort
int partition(int arr[],int s,int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
int quickSort(int arr[],int s,int e){
    if(s<e){
        int pivot=partition(arr,s,e);
        quickSort(arr,s,pivot-1);
        quickSort(arr,pivot+1,e);
    }
}

// Test sorting performance for a given case
void testSortingPerformance(const vector<int>& data, const string& caseName, int arraySize) {
    int* arr = new int[arraySize];
    copy(data.begin(), data.end(), arr);
    
    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arraySize - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;
    
    // Write the results to a CSV file
    ofstream file("sorting_performanceq3.csv", ios::app);
    file << caseName << "," << arraySize << "," << duration.count() << "\n";
    file.close();
    
    delete[] arr;
}

int main() {
    ofstream file("sorting_performanceq3.csv");
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

    cout << "Performance testing complete. Results written to sorting_performanceq3.csv" << endl;

    return 0;
}
