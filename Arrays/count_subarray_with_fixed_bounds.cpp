// Count subarray with fixed bounds
// You are given an integer array nums and two integers minK and maxK.
// A fixed-bound subarray of nums is a subarray that satisfies the following conditions: The minimum value in the subarray is equal to minK.
// The maximum value in the subarray is equal to maxK. Return the number of fixed-bound subarrays. A subarray is a contiguous part of an array.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;
    int maxi = -1, mini = -1;
    int s = nums.size();

    for (int r = 0, l = 0; r < s; r++) {
        int x = nums[r];
        
        if (x < minK || x > maxK) {
            l = r + 1;
            continue;
        }

        if (x == maxK) maxi = r;
        if (x == minK) mini = r;

        ans += max(min(maxi, mini) - l + 1, 0);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 3, 5, 2, 7, 5}; // Example input
    int minK = 1;
    int maxK = 5;

    long long result = countSubarrays(nums, minK, maxK);
    cout << "Count of valid subarrays: " << result << endl;

    return 0;
}