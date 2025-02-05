//Reverse a stack using recursion
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&s, int element) {
    //Base case
    if(s.empty()) {
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    insertAtBottom(s, element);
    s.push(num);
}

void reverseStack(stack<int>&s) {
    //base case
    if(s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    reverseStack(s);

    insertAtBottom(s, num);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverseStack(s);

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}