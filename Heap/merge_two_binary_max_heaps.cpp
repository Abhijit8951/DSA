// Merge two binary max heaps
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

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

vector<int> mergeHeaps(vector<int> &a, vector<int> &b) {
    vector<int> ans;

    // Merge both heaps
    for (auto i : a) {
        ans.push_back(i);
    }

    for (auto i : b) {
        ans.push_back(i);
    }

    // Build max heap using merged array
    int size = ans.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(ans, size, i);
    }

    return ans;
}

int main() {
    vector<int> heap1 = {10, 5, 6, 2};
    vector<int> heap2 = {12, 7, 9};

    vector<int> mergedHeap = mergeHeaps(heap1, heap2);

    cout << "Merged Max-Heap: ";
    for (int num : mergedHeap) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}