//Design a stack that supports getMin() in O(1) time and O(1) extra space
// Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.
// Implement the following public functions :
// 1. push(data) :
// This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
// 2. pop() :
// It pops the element from the top of the stack and returns nothing.
// 3. top() :
// It returns the element being kept at the top of the stack.
// 4.  getMin() :
// It returns the smallest element present in the stack.
// Operations Performed on the Stack:
// Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)
// Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)
// Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)
// Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function)
#include <stack>
#include <limits.h>
#include <iostream>
using namespace std;

stack<int> s;
int mini = INT_MAX;

void push(int data) {
    if (s.empty()) {
        s.push(data);
        mini = data;
    } else {
        if (data < mini) {
            int val = 2 * data - mini;
            s.push(val);
            mini = data;
        } else {
            s.push(data);
        }
    }
}

void pop() {
    if (s.empty()) {
        return;
    }

    int curr = s.top();
    s.pop();
    
    if (curr < mini) {
        int val = 2 * mini - curr;
        mini = val;
    }
}

int top() {
    if (s.empty()) {
        return -1;
    }

    int curr = s.top();
    
    if (curr < mini) {
        return mini;
    } else {
        return curr;
    }
}

int getMin() {
    if (s.empty()) {
        return -1;
    }
    return mini;
}

int main() {
    push(5);
    push(2);
    push(8);
    push(1);
    push(10);
    
    cout << "Minimum: " << getMin() << endl; // 1
    pop();
    cout << "Minimum: " << getMin() << endl; // 1
    pop();
    cout << "Minimum: " << getMin() << endl; // 2
    pop();
    cout << "Minimum: " << getMin() << endl; // 2
    pop();
    cout << "Minimum: " << getMin() << endl; // 5
    
    return 0;
}