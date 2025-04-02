// second most repeated words
// You are given an array of strings ‘ARR’. You have to find out the second most repeated word in the array ‘ARR’. It is guaranteed every string occurs a unique number of times in the array. If there is only one unique string in the array, return an empty string.
// Example:-
// S = [‘aaa’, ‘bbb’, ‘ccc’, ‘aaa’, ‘bbb’, ‘aaa’]
// ANSWER:- The answer should be ‘bbb’ as it is repeated 2 times and is the second most repeated word in the array [after the word ‘aaa’ which is repeated 3 times].
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string second_repeat(vector<string> &arr, int n) {
    unordered_map<string, int> freq;

    for (const string &s : arr) {
        freq[s]++;
    }

    int largest = INT_MIN, secLargest = INT_MIN;

    for (const auto &pair : freq) {
        if (pair.second > largest) {
            secLargest = largest;
            largest = pair.second;
        } else if (pair.second > secLargest && pair.second < largest) {
            secLargest = pair.second;
        }
    }

    for (const auto &pair : freq) {
        if (pair.second == secLargest) {
            return pair.first;
        }
    }

    return ""; 
}

int main() {
    vector<string> arr = {"apple", "banana", "apple", "orange", "banana", "banana", "grape"};
    cout << second_repeat(arr, arr.size()) << endl; 
    return 0;
}