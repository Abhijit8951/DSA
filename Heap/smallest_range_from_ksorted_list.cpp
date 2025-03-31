// Smallest range from K sorted lists
// You are given ‘K’ lists containing non-negative integers. Each list has a size ‘N’ and is sorted in non-decreasing order. You need to find the minimum length of a range such that at least one element of each list must be included in that range.
// For example : The given list are [4, 7, 30], [1, 2, 12] and [20, 40, 50]. The range [7, 20], hence the length of this range is 14. This is the only possible range having the minimum length.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node {
public:
    int data, row, col;
    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

// Min-heap comparator for priority_queue
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap (smallest element on top)
    }
};

int kSorted(vector<vector<int>>& arr, int k, int n) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    // Insert first elements of each list into minHeap
    for (int i = 0; i < k; i++) {
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, i, 0));
    }

    int start = mini, end = maxi;

    while (!minHeap.empty()) {
        Node* temp = minHeap.top();
        minHeap.pop();
        mini = temp->data;

        // Update smallest range
        if (maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // If more elements are in the same row, push next element
        if (temp->col + 1 < n) {
            int nextVal = arr[temp->row][temp->col + 1];
            maxi = max(maxi, nextVal);
            minHeap.push(new Node(nextVal, temp->row, temp->col + 1));
        } else {
            break; // One list is exhausted, so stop
        }
    }

    return (end - start + 1);
}

int main() {
    vector<vector<int>> arr = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = arr.size();
    int n = arr[0].size();

    cout << "Smallest range: " << kSorted(arr, k, n) << endl;
    return 0;
}