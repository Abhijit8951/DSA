// Count the number of good subarrays (LC: 2537)
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
// A subarray is a contiguous non-empty sequence of elements within an array.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countGood(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;
    long long goodSubarraysCount = 0;
    int left = 0;                         // Left pointer for the sliding window

    // Traverse the array with a sliding window
    for (int right = 0; right < nums.size(); right++) {
        // Decrease k by the number of existing occurrences of nums[right]
        k -= frequencyMap[nums[right]];

        // Increment the count of nums[right] in the map
        frequencyMap[nums[right]]++;

        // If current window has at least k good pairs, shrink it from the left
        while (k <= 0) {
            frequencyMap[nums[left]]--;
            k += frequencyMap[nums[left]];
            left++;
        }

        // For each position, the number of valid subarrays ending at 'right' is equal to 'left'
        goodSubarraysCount += left;
    }

    return goodSubarraysCount;
}

int main() {
    vector<int> nums = {1, 1, 1, 1};
    int k = 5;
    cout << "Number of good subarrays: " << countGood(nums, k) << endl;
    return 0;
}