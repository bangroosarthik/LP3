#include <bits/stdc++.h>
using namespace std;
// Deterministic Partition Function
int deterministicPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// Randomized Partition Function
int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1); // Random index between low and high
    swap(arr[low], arr[randomIndex]); // Swap the randomly chosen pivot with the first element
    return deterministicPartition(arr, low, high); // Use deterministic partition with the random pivot
}

// Quick Sort function with user-selected partition
void quickSortHelper(vector<int> &arr, int low, int high, bool isRandomized) {
    if (low < high) {
        int pIndex;
        if (isRandomized) {
            pIndex = randomizedPartition(arr, low, high);
        } else {
            pIndex = deterministicPartition(arr, low, high);
        }
        quickSortHelper(arr, low, pIndex - 1, isRandomized);
        quickSortHelper(arr, pIndex + 1, high, isRandomized);
    }
}

// Main Quick Sort function
vector<int> quickSort(vector<int> arr, bool isRandomized) {
    quickSortHelper(arr, 0, arr.size() - 1, isRandomized);
    return arr;
}

// Display function
void displayArray(const vector<int> &arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

// Menu-driven function
void quickSortMenu() {
    int choice;
    vector<int> arr;
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;
    arr.resize(n);

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nChoose Quick Sort Type:\n";
    cout << "1. Deterministic Quick Sort\n";
    cout << "2. Randomized Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "\nBefore Sorting:\n";
    displayArray(arr);

    if (choice == 1) {
        arr = quickSort(arr, false); // Deterministic sort
        cout << "\nAfter Deterministic Quick Sort:\n";
    } else if (choice == 2) {
        arr = quickSort(arr, true); // Randomized sort
        cout << "\nAfter Randomized Quick Sort:\n";
    } else {
        cout << "Invalid choice. Exiting.\n";
        return;
    }

    displayArray(arr);
}

int main() {
    srand(time(0)); // Seed the random number generator for randomized Quick Sort
    quickSortMenu();
    return 0;
}
