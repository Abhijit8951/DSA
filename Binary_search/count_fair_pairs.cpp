// Count Fair Pairs (LC: 2563)
// Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
// A pair (i, j) is fair if:
// 0 <= i < j < n, and
// lower <= nums[i] + nums[j] <= upper
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int n = nums.size();
    int i = 0;

    while (i < n) {
        int l = -1, r = -1;

        // Binary search for lower bound
        int low = i + 1, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[i] + nums[mid] >= lower) {
                r = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // Binary search for upper bound
        low = i + 1, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[i] + nums[mid] <= upper) {
                l = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (r != -1 && l != -1 && l >= r) {
            count += (l - r + 1);
        }

        i++;
    }

    return count;
}

int main(){
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    int ans = countFairPairs(nums, lower, upper);

    cout << "The number of fair pairs are: " << ans << endl;

    return 0;
}