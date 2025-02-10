//Maximum difference between adjacent elements in a circular array
//Given a circular array nums, find the maximum absolute difference between adjacent elements.
// Note: In a circular array, the first and last elements are adjacent.
// Example 1:
// Input: nums = [1,2,4]
// Output: 3
// Explanation: Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
// Example 2:
// Input: nums = [-5,-10,-5]
// Output: 5
// Explanation: The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.
#include<iostream>
#include<vector>
using namespace std;

int getAns(vector<int>& nums) {
    int maxi = INT_MIN, n = nums.size();

    if (n == 2) {
        return abs(nums[1] - nums[0]);
    }

    for (int i = 0; i < n - 1; i++) {
        maxi = max(maxi, abs(nums[i + 1] - nums[i]));
    }

    return max(maxi, abs(nums[n - 1] - nums[0]));
}

int main() {
    vector<int> nums = {1, 2, 4};
    int ans = getAns(nums);

    cout << "The maximum difference is: " << ans << endl;


    return 0;
}