// Minimum cost of ropes
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap

    // Push all elements into the priority queue
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i]);
    }

    int cost = 0;
    
    // Process until only one element is left
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main() {
    vector<int> arr = {4, 3, 2, 6};

    int result = minCost(arr);

    cout << "Minimum cost to connect ropes: " << result << endl;

    return 0;
}