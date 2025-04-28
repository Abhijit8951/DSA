// Count subarrays with score less than k
// The score of an array is defined as the product of its sum and its length.
// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.
// A subarray is a contiguous sequence of elements within an array.
#include <iostream>
#include <vector>
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    long long count = 0;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];

        // Shrink the window if the condition is not satisfied
        while (left <= right && sum * (right - left + 1) >= k) {
            sum -= nums[left];
            left++;
        }

        // Add the number of valid subarrays ending at 'right'
        count += (right - left + 1);
    }

    return count;
}

int main() {
    vector<int> nums = {1, 2, 3};
    long long k = 10;

    long long result = countSubarrays(nums, k);
    cout << "Number of valid subarrays: " << result << endl;

    return 0;
}