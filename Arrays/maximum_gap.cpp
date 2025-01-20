//Maximum gap(LC-164)
//Given an integer array nums, return the maximum difference between two successive elements in 
// its sorted form. If the array contains less than two elements, return 0.
// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
#include <iostream>
#include <vector>
using namespace std;

int maximumGap(vector<int>& nums){
    int n = nums.size();

    if(n < 2) return 0;

    sort(nums.begin(), nums.end());
    int maxGap = INT_MIN;
    for(int i=1; i<n; i++){
        maxGap = max(maxGap, nums[i] - nums[i-1]);
    }
    return maxGap;
}

int main(){
    vector<int> nums = {3, 6, 9, 1};

    cout << "The maximum gap is: " << maximumGap(nums) << endl;


    return 0;
}