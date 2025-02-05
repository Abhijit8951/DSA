//Sort a stack
#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int>& s, int num) {
    //Base case
    if(s.empty() || s.top() < num) {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();

    //Recursive call
    sortedInsert(s, num);
    s.push(n);
}

void sortStack(stack<int>& s) {
    //Base case
    if(s.empty()) {
        return;
    }

    int num = s.top();
    s.pop();

    //Recursive call
    sortStack(s);

    sortedInsert(s, num);
}

int main() {
    stack<int> s;
    s.push(7);
    s.push(-3);
    s.push(4);
    s.push(9);
    s.push(-9);

    sortStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;


    return 0;
}