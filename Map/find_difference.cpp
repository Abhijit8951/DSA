#include <iostream>
#include <unordered_map>
using namespace std;

char findRes(string s, string t) {
    unordered_map<int, int> m;
    
    for(char c : s) {
        m[c]++;
    }

    for(char c : t) {
        if(m.find(c) == m.end() || m[c] == 0) {
            return c;
        } else {
            m[c]--;
        }
    }
    return ' ';
}

int main() {
    string s = "abcd";
    string t = "abcde";

    char res = findRes(s, t);
    cout << "The difference character is: " << res << endl;

    return 0;
}