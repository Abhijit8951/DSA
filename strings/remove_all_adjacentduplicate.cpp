#include <iostream>
#include <string>
using namespace std;

int main(){
    string str = "azxxzy";
    stack<char> stack;
    string result;

    for(char c : str){
        if(!stack.empty() && stack.top() == c){
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    while(!stack.empty()){
        result.push_back(stack.top());
        stack.pop();
    }

    reverse(result.begin(), result.end());

    for(char ch : result){
        cout << ch;
    }
    cout << endl;


    return 0;
}