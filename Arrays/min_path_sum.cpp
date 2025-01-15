//Minimu  path sum
//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom 
//right, which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.
#include <iostream>
#include <vector>
using namespace std;

int helper(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& dp){
        if(i == nums.size()-1 and j == nums[0].size()-1){
            return dp[i][j] = nums[i][j];
        }
        if(i >= nums.size() or j >= nums[0].size()){
            return INT_MAX;
        }
        

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int sum = nums[i][j] + min(helper(nums, i, j+1, dp), helper(nums, i+1, j, dp));

        return dp[i][j] = sum;
    }

int main(){
    vector<vector<int>> nums = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int m = nums.size();
    int n = nums[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int minSum = helper(nums, 0, 0, dp);

    cout << "The minimum path sum is: " << minSum << endl;


    return 0;
}