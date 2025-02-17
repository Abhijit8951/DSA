//Reverse First K elements of Queue
//Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.
//Input: 1 2 3 4 5
// Output: 3 2 1 4 5
// Explanation: 
// After reversing the given
// input from the 3rd position the resultant
// output will be 3 2 1 4 5.
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    
    for(int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    int t = q.size() - k;
    while(t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}

int main() {
    queue<int> q;
    int n, k, val;
    
    cout << "Enter number of elements in queue: ";
    cin >> n;
    
    cout << "Enter elements of queue: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    
    cout << "Enter value of k: ";
    cin >> k;
    
    queue<int> modifiedQueue = modifyQueue(q, k);
    
    cout << "Modified Queue: ";
    while(!modifiedQueue.empty()) {
        cout << modifiedQueue.front() << " ";
        modifiedQueue.pop();
    }
    cout << endl;
    
    return 0;
}