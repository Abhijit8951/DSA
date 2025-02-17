//Stream First Non-repeating
//Given an input stream s consisting only of lowercase alphabets. While reading characters from the stream, 
//you have to tell which character has appeared only once in the stream upto that point. If there are many characters 
//that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.
//Input: s = "aabc"
// Output: "a#bb"
// Explanation: For every ith character we will consider the string from index 0 till index i first non repeating character is as follow- "a" - first non-repeating character is 'a' "aa" - no non-repeating character 
//so '#' "aab" - first non-repeating character is 'b' "aabc" - there are two non repeating characters 'b' and 'c',  first non-repeating character is 'b' because 'b' comes before 'c' in the stream.
#include<iostream>
#include<string>
#include<unordered_map>
#include <stack>
using namespace std;

string FirstNonRepeating(string &s) {
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        count[ch]++;
        q.push(ch);
        
        while(!q.empty()) {
            if(count[q.front()] > 1) {
                q.pop();
            } else {
                ans.push_back(q.front());
                break;
            }
        
        }
        if(q.empty()) {
            ans.push_back('#');
        }
    }
    return ans;
}

int main() {
    string str = "aabc";
    string ans = FirstNonRepeating(str);

    cout << ans << endl;

    return 0;
}