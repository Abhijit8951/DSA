// Ransom Note
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.
// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> dictionary;

    // Count characters in the magazine
    for (char c : magazine) {
        if (dictionary.find(c) == dictionary.end()) {
            dictionary[c] = 1;
        } else {
            dictionary[c]++;
        }
    }

    // Check if ransomNote can be constructed
    for (char c : ransomNote) {
        if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
            dictionary[c]--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    string ransomNote, magazine;

    cout << "Enter ransom note: ";
    cin >> ransomNote;

    cout << "Enter magazine text: ";
    cin >> magazine;

    if (canConstruct(ransomNote, magazine)) {
        cout << "Yes, ransom note can be constructed from the magazine." << endl;
    } else {
        cout << "No, ransom note cannot be constructed from the magazine." << endl;
    }

    return 0;
}