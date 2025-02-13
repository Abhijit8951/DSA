//Max Sum of a Pair With Equal Sum of Digits (LC-2342)
//You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
// Example 1:
// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
// So the maximum sum that we can obtain is 54.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

int add(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    vector<int> arr = {18, 43, 36, 13, 7};
    unordered_map<int, int> digitSumMap;
    int maxi = -1;

    for (int num : arr) {
        int digitSum = add(num);
        
        if (digitSumMap.find(digitSum) != digitSumMap.end()) {
            maxi = max(maxi, num + digitSumMap[digitSum]);
        }

        digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
    }

    cout << maxi << endl;

    return 0;
}