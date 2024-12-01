//Find all subsets using backtracking
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
    //if no need to include the current element
    printSubset(nums, ans, i+1);
    
}

int main(){
    vector<int> nums = {1, 2, 3};
    vector<int> ans;

    printSubset(nums, ans, 0);


    return 0;
}