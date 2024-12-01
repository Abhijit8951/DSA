//Find all subsets using backtracking(When the array is having duplicate elements)
#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &nums, vector<int> &ans, int i){
    if(i == nums.size()){
        for(int val : ans){
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    //if need to include the current element
    ans.push_back(nums[i]);
    printSubset(nums, ans, i+1);


    ans.pop_back(); //backtrack
    
    //skip the duplicate elements
    int idx = i+1;
    while(idx < nums.size() && nums[idx] == nums[i]){
        idx++;
    }
    //if no need to include the current element
    printSubset(nums, ans, idx);
    
}

int main(){
    vector<int> nums = {1, 2, 2};
    vector<int> ans;

    printSubset(nums, ans, 0);


    return 0;
}