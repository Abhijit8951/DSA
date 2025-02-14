//Reverse a queue
#include <iostream>
#include <queue>
using  namespace std;

class Solution {
public:
    void reverseQueueHelper(std::queue<int>& q) {
        if (q.empty()) return; // Base case

        int front = q.front();
        q.pop();

        reverseQueueHelper(q); // Recursive call

        q.push(front); // Put the front element at the back
    }

    queue<int> reverseQueue(std::queue<int>& q) {
        reverseQueueHelper(q);
        return q;
    }
};

int main() {
    std::queue<int> q;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    Solution sol;
    q = sol.reverseQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}