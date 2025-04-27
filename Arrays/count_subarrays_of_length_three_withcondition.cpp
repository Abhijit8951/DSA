// Count Subarrays of Length Three With a Condition
// Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& nums) {
    int ans = 0;
    for (int i = 2; i < nums.size(); ++i) {
        ans += ((nums[i] + nums[i-2]) * 2 == nums[i-1]) ? 1 : 0;
    }
    return ans;
}

int main() {
    vector<int> nums;
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    int result = countSubarrays(nums);
    cout << "Number of valid subarrays: " << result << endl;
    
    return 0;
}