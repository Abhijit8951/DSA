// Count complete subarrays (LC: 2799)
// You are given an array nums consisting of positive integers.
// We call a subarray of an array complete if the following condition is satisfied:
// The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
// Return the number of complete subarrays.
// A subarray is a contiguous non-empty part of an array.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countCompleteSubarrays(vector<int>& nums) {
    unordered_set<int> distinctElements(nums.begin(), nums.end());
    int totalDistinct = distinctElements.size();
    int count = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        unordered_set<int> currentSet;
        for (int j = i; j < n; ++j) {
            currentSet.insert(nums[j]);
            if (currentSet.size() == totalDistinct) {
                count += (n - j);
                break;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = countCompleteSubarrays(nums);
    cout << "Number of complete subarrays: " << result << endl;

    return 0;
}