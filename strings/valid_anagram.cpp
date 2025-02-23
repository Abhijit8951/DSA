// Valid Anagram
//Given two strings s and t, return true if t is an  anagram of s, and false otherwise.
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:
// Input: s = "rat", t = "car"
// Output: false
#include <iostream>
#include <cstring>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    int counter[256] = {0}; // Assuming ASCII characters

    for (char ch : s) {
        counter[ch]++;
    }

    for (char ch : t) {
        if (counter[ch] == 0) {
            return false;
        }
        counter[ch]--;
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams.\n";
    } else {
        cout << "The strings are not anagrams.\n";
    }

    return 0;
}