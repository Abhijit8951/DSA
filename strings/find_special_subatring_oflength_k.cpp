// Find special substring of length K (LC: 3456)
//Determine if there exists a substring of length exactly k in s that satisfies the following conditions:
// The substring consists of only one distinct character (e.g., "aaa" or "bbb").
// If there is a character immediately before the substring, it must be different from the character in the substring.
// If there is a character immediately after the substring, it must also be different from the character in the substring. Return true if such a substring exists. Otherwise, return false.
// Example 1:
// Input: s = "aaabaaa", k = 3
// Output: true
// Explanation: The substring s[4..6] == "aaa" satisfies the conditions.
// It has a length of 3.
// All characters are the same.
// The character before "aaa" is 'b', which is different from 'a'.
// There is no character after "aaa".
// Example 2:
// Input: s = "abc", k = 2
// Output: false
// Explanation: There is no substring of length 2 that consists of one distinct character and satisfies the conditions.
#include <iostream>
#include <string>
using namespace std;

bool hasSpecialSubstring(string s, int k) {
    int count = 1;
    for (int i = 1; i < s.size(); i++, count++) {
        if (s[i] != s[i - 1] && count == k) return true;
        if (s[i] != s[i - 1]) count = 0;
    }
    return (count == k);
}

int main() {
    string s;
    int k;
    
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    if (hasSpecialSubstring(s, k)) {
        cout << "The string has a special substring of length " << k << ".\n";
    } else {
        cout << "The string does not have a special substring of length " << k << ".\n";
    }

    return 0;
}