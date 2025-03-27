#include <iostream>
using namespace std;

void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Function to insert an element into the heap
void insertHeap(int heap[], int &size, int k, int value) {
    if (size < k) {
        heap[size] = value;
        size++;

        // Heapify up
        int i = size - 1;
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    } else if (heap[0] < value) {
        heap[0] = value;
        heapify(heap, k, 0);
    }
}

int getKthLargest(int arr[], int n, int k) {
    int heap[k];  // Min heap of size k
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            insertHeap(heap, heapSize, k, sum);
        }
    }
    return heap[0];  // K-th largest element
}

int main() {
    int arr[] = {10, -10, 20, -40};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The " << k << "-th largest subarray sum is: " << getKthLargest(arr, n, k) << endl;
    return 0;
}