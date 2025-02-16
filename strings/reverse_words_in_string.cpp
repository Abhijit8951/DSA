//Reverse words in a string
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    // Split the input string into words
    istringstream iss(s);
    vector<string> words;
    string word;
    
    while (iss >> word) {
        // Reverse each word and add to the vector
        reverse(word.begin(), word.end());
        words.push_back(word);
    }

    // Join the reversed words to form the final result
    string result = "";
    for (const string& reversedWord : words) {
        result += reversedWord + " ";
    }

    if (!result.empty()) {
        result.pop_back();  // Remove the extra space at the end
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);
    
    string reversed = reverseWords(s);
    cout << "Reversed words: " << reversed << endl;

    return 0;
}