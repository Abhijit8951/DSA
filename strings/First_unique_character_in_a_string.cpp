//First unique character in a string(LC: 387)
//Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
//Example 1:
// Input: s = "leetcode"
// Output: 0
// Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> count;

    for (char ch : s) {
        count[ch]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (count[s[i]] == 1) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    string str = "leetcode";
    int ans = firstUniqChar(str);

    cout << ans << endl;

    return 0;
}