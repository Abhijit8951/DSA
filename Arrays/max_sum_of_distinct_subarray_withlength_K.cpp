// Maximum sum of distinct subarrays with length K
// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long maximumSubarraySum(vector<int>& nums, int k) {
    set<int> s;
    int n = nums.size();
    long long sum = 0;
    long long mx = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (s.count(nums[i])) {
            sum -= nums[j];
            s.erase(nums[j]);
            j++;
        }

        s.insert(nums[i]);
        sum += nums[i];

        if (s.size() == k) {
            mx = max(mx, sum);
            sum -= nums[j];
            s.erase(nums[j]);
            j++;
        }
    }
    return mx;
}

int main() {
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 3;

    long long result = maximumSubarraySum(nums, k);
    cout << "Maximum subarray sum with exactly " << k << " distinct elements: " << result << endl;

    return 0;
}