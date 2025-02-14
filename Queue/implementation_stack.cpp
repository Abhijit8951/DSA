//Implementation of queue using stack
#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> in_stack, out_stack;

    void transfer() {
        while (!in_stack.empty()) {
            out_stack.push(in_stack.top());
            in_stack.pop();
        }
    }
    
public:
    MyQueue() {}

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        if (out_stack.empty()) {
            transfer();
        }
        if (out_stack.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int topElement = out_stack.top();
        out_stack.pop();
        return topElement;
    }

    int peek() {
        if (out_stack.empty()) {
            transfer();
        }
        if (out_stack.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return out_stack.top();
    }

    bool empty() {
        return in_stack.empty() && out_stack.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Front: " << q.peek() << "\n";
    cout << "Popped: " << q.pop() << "\n";
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "\n";
    cout << "Popped: " << q.pop() << "\n";
    cout << "Empty: " << (q.empty() ? "Yes" : "No") << "\n";
    return 0;
}