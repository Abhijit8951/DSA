// Find the Index of the First Occurrence in a String (LC: 28)
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if (haystack.length() < needle.length()) {
        return -1;
    }

    for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        if (haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }

    return -1;
}

int main() {
    string haystack, needle;
    cout << "Enter the main string (haystack): ";
    cin >> haystack;
    cout << "Enter the substring to search (needle): ";
    cin >> needle;

    int result = strStr(haystack, needle);
    if (result != -1) {
        cout << "Substring found at index: " << result << endl;
    } else {
        cout << "Substring not found." << endl;
    }

    return 0;
}