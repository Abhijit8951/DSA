// Count and Say
// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
// countAndSay(1) = "1"
// countAndSay(n) is the run-length encoding of countAndSay(n - 1).
// Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
// Given a positive integer n, return the nth element of the count-and-say sequence.
#include <iostream>
#include <string>
using namespace std;

string countAndSay(int n) {
    string s = "1";
    string s2;

    for (int i = 0; i < n - 1; i++) {
        char prev = s[0];
        int cnt = 1;

        for (int j = 1; j < s.length(); j++) {
            if (s[j] == prev) {
                cnt++;
            } else {
                s2 += to_string(cnt);
                s2 += prev;
                cnt = 1;
            }
            prev = s[j];
        }

        s2 += to_string(cnt);
        s2 += prev;
        s = s2;
        s2.clear();
    }

    return s;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    string result = countAndSay(n);
    cout << "The " << n << "th term in the count-and-say sequence is: " << result << endl;

    return 0;
}