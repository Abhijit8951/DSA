//Three Sum Closest (LC-16)
//Given an integer array nums of length n and an integer target, find three integers in 
//nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    sort(nums.begin(), nums.end());
    int ans, n = nums.size(), min_distance = INT_MAX;
    for(int i=0; i<n-2; i++){
        int left = i+1, right = n-1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            int distance = abs(sum - target);
            if(distance < min_distance){
                ans = sum;
                min_distance = distance;
            }
            if(sum < target) right--;
            else if(sum > target) left++;
            else cout << sum << endl;
        }
    }
    cout << ans << endl;


    return 0;
}