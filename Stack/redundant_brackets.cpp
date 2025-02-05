//Redundant brackets(CS-6)
//Given valid mathematical expressions in the form of string. You are supposed to return true if the given expression contains a
//pair of redundant brackets, else return false. the given string only contains '(',')','+','-','*','/' and lowercase english letters
#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> st;
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            if(ch == ')') {
                bool isRedundant = true;

                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int main() {
    string s = "((a+b))";

    bool res = findRedundantBrackets(s);

    if(res) {
        cout << "The string contains redundant brackets." << endl;
    } else {
        cout << "The string doesn't contains redundant brackets." << endl;
    }


    return 0;
}