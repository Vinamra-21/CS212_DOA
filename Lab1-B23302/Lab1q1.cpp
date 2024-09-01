#include <bits/stdc++.h>
#include <vector>
#include <chrono> 
#include <fstream>

using namespace std;

//insertion sort
vector<int> insertionSort(vector<int> arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j--];
        }
        arr[j + 1] = key;
    }

    return arr;
}

// Performance testing function
void testSortingPerformance(vector<int> arr, const string& caseName, int arraySize) {
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;

    // results to a CSV file
    ofstream file("sorting_performanceq1.csv", ios::app);//results will be added without overwriting
    file << caseName << "," << arraySize << "," << duration.count() << "\n";//gives magnitude of time taken
    file.close();
}

int main() {
    ofstream file("sorting_performanceq1.csv");
    file << "Case,Array Size,Time (seconds)\n"; // CSV header
    file.close();

    vector<int> randomData, sortedData, reverseData, duplicateData;

    // test for different array sizes
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

    cout << "Performance testing complete. Results written to sorting_performanceq1.csv" << endl;

    return 0;
}
