//Minimum size subarray sum
//Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
//whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to find the minimum subarray length
int minSubArrayLen(int target, vector<int>& nums) {
    int minLen = numeric_limits<int>::max();
    int left = 0;
    int curSum = 0;

    for (int right = 0; right < nums.size(); right++) {
        curSum += nums[right];

        while (curSum >= target) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
            }
            curSum -= nums[left];
            left++;
        }
    }

    return minLen != numeric_limits<int>::max() ? minLen : 0;
}

int main() {
    int target, n;

    // Input target sum
    cout << "Enter the target sum: ";
    cin >> target;

    // Input size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    // Input array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call the function and display the result
    int result = minSubArrayLen(target, nums);
    if (result == 0) {
        cout << "No subarray meets the target sum." << endl;
    } else {
        cout << "The minimum length of a subarray with sum >= " << target << " is: " << result << endl;
    }

    return 0;
}