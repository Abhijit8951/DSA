// Merge k sorted arrays
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data, i, j;
    Node(int data, int row, int col) : data(data), i(row), j(col) {}
};

// Min-heap comparison function using `greater<>`
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    auto compare = [](const Node& a, const Node& b) {
        return a.data > b.data; // Min-heap: smallest element at top
    };
    
    priority_queue<Node, vector<Node>, decltype(compare)> minHeap(compare);

    for (int i = 0; i < k; i++) {
        if (!kArrays[i].empty()) { 
            minHeap.emplace(kArrays[i][0], i, 0);
        }
    }

    vector<int> ans;

    while (!minHeap.empty()) {
        Node temp = minHeap.top();
        minHeap.pop();
        ans.push_back(temp.data);

        int i = temp.i, j = temp.j;
        
        // Push the next element from the same row
        if (j + 1 < kArrays[i].size()) {
            minHeap.emplace(kArrays[i][j + 1], i, j + 1);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> kArrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    vector<int> mergedArray = mergeKSortedArrays(kArrays, kArrays.size());

    for (int num : mergedArray) {
        cout << num << " ";
    }
    return 0;
}