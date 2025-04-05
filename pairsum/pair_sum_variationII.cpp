// Pair Sum
// Problem statement
// You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'.
// Note:
// Each pair should be sorted i.e the first value should be less than or equals to the second value. 
// Return the list of pairs sorted in non-decreasing order of their first value. In case if two pairs have the same first value, the pair with a smaller second value should come first.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s) {
    unordered_map<int, int> freq;
    vector<vector<int>> result;

    for (int num : arr) {
        int complement = s - num;

        if (freq.find(complement) != freq.end()) {
            int count = freq[complement];
            while (count--) {
                result.push_back({min(num, complement), max(num, complement)});
            }
        }

        freq[num]++;
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {1, 3, 2, 2, 4, 3};
    int targetSum = 5;

    vector<vector<int>> pairs = pairSum(arr, targetSum);

    for (const auto &pair : pairs) {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}