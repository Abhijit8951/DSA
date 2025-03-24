// Heap Sort (TC: O(NlogN))
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and heapify recursively
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n) {

    int i = n / 2;
    while (i >= 1) {
        heapify(arr, n, i);
        i--;
    }

    int size = n;

    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {-1, 12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]) - 1;

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}