//Min Stack
//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:
// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.
// Example 1:
// Input:["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]
// Output:[null,null,null,null,-3,null,0,-2]
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if (!s.empty()) {
            return s.top().first;
        }
        return -1; // Return an error value if stack is empty
    }

    int getMin() {
        if (!s.empty()) {
            return s.top().second;
        }
        return -1; // Return an error value if stack is empty
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    
    cout << "Min: " << minStack.getMin() << endl; // Output: -3
    
    minStack.pop();
    
    cout << "Top: " << minStack.top() << endl; // Output: 0
    cout << "Min: " << minStack.getMin() << endl; // Output: -2

    return 0;
}