// Kth smallest element in an unsorted array
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;
    
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    
    for (int i = k; i < arr.size(); i++) {
        if (arr[i] < pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    return pq.top();
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    cout << "The " << k << "th smallest element is " << kthSmallest(arr, k) << endl;
    return 0;
}