//Valid parentheses
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            st.push(str[i]);
        } else {
            if (st.empty()) {
                return false;
            }

            if ((st.top() == '(' && str[i] == ')') ||
                (st.top() == '[' && str[i] == ']') ||
                (st.top() == '{' && str[i] == '}')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    string input;
    cout << "Enter a string of parentheses: ";
    cin >> input;
    
    if (isValid(input)) {
        cout << "Valid parentheses sequence" << endl;
    } else {
        cout << "Invalid parentheses sequence" << endl;
    }
    
    return 0;
}
