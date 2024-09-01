#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

// Partition function that uses the last element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Randomized partition function that selects a random pivot
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    return partition(arr, low, high);
}

// The main function that implements Randomized Quicksort
void randomizedQuicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuicksort(arr, low, pi - 1);
        randomizedQuicksort(arr, pi + 1, high);
    }
}

// Test sorting performance for a given case
void testSortingPerformance(const vector<int>& data, const string& caseName, int arraySize) {
    int* arr = new int[arraySize];
    copy(data.begin(), data.end(), arr);

    auto start = chrono::high_resolution_clock::now();
    randomizedQuicksort(arr, 0, arraySize - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long double> duration = end - start;

    ofstream file("sorting_performanceq4.csv", ios::app);
    file << caseName << "," << arraySize << "," << duration.count() << "\n";
    file.close();

    delete[] arr;
}

int main() {
    srand(time(0)); // Seed the random number generator

    ofstream file("sorting_performanceq4.csv");
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
            reverseData.push_back(size - i - 1); 
            duplicateData.push_back(42);  
        }

        // Test each case
        testSortingPerformance(randomData, "Random", size);
        testSortingPerformance(sortedData, "Sorted", size);
        testSortingPerformance(reverseData, "Reverse-Sorted", size);
        testSortingPerformance(duplicateData, "Duplicate", size);
    }

    cout << "Performance testing complete. Results written to sorting_performanceq4.csv" << endl;

    return 0;
}
