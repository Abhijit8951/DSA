//Stacks
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);

    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    //swap functions swaps the elements of a stack with another stack
    stack<int> s2;
    s2.swap(s);
    cout << "Size of s: " << s.size() << endl;
    cout << "Size of s2: " << s2.size() << endl;


    return 0;
}