//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
#include <iostream>
#include <vector>
using namespace std;

void getPermutation(vector<int>& nums, int idx, vector<vector<int>>& ans){
    if(idx == nums.size()){
        ans.push_back(nums);
    }

    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx], nums[i]);
        getPermutation(nums, idx+1, ans);
        swap(nums[idx], nums[i]); //Backtrack to the original
    }
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    getPermutation(nums, 0, ans);

    for (const auto& row : ans) {
        for (int el : row) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}