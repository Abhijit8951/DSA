// isomerphic string
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Explanation:
// The strings s and t can be made identical by:
// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> mapST; // map from s -> t
    unordered_map<char, char> mapT;  // map from t -> s

    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i];
        char c2 = t[i];

        // Check if c1 was already mapped to something
        if (mapST.find(c1) != mapST.end()) {
            if (mapST[c1] != c2) {
                return false;
            }
        } else {
            mapST[c1] = c2;
        }

        // Also check reverse mapping: c2 -> c1
        if (mapT.find(c2) != mapT.end()) {
            if (mapT[c2] != c1) {
                return false;
            }
        } else {
            mapT[c2] = c1;
        }
    }

    return true;
}

int main() {
    string s, t;
    cout << "Enter first string: ";
    cin >> s;
    cout << "Enter second string: ";
    cin >> t;

    if (isIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}