//Longest substring without repeating characters
//Given a string s, find the length of the longest substring
//  without repeating characters.
//Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    string s = "abcabcbb";
    int left = 0;
    int maxLength = 0;
    unordered_set<char> charSet;

    for (int right = 0; right < s.length(); right++) {
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }

        charSet.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    cout << "The length of longest substring is: " << maxLength << endl;


    return 0;
}