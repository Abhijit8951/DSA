//Combination sum
// Given an array of distinct integers candidates and a target integer target, return a list of 
// all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations 
// in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency of at least one of the chosen numbers is different.

#include <iostream>
#include <vector>
#include <set>
using namespace std;


set<vector<int>> s;
void getCombination(vector<int> &arr, int idx, vector<int> &combination, int target, vector<vector<int>> &ans){

    if(target == 0){
        if(s.find(combination) == s.end()){
            ans.push_back(combination);
            s.insert(combination);
        }
        
        return;
    }

    if(target < 0 || idx >= arr.size()){
        return;
    }
    

    //single inclusion
    combination.push_back(arr[idx]);
    getCombination(arr, idx+1, combination, target-arr[idx], ans);   //You can remove this line but don't forget to remove the set and it's implementations

    //Multiple inclusion
    getCombination(arr, idx, combination, target-arr[idx], ans);

    //Exclusion
    combination.pop_back();  //Backtrack
    getCombination(arr, idx+1, combination, target, ans);
}

int main(){
    vector<int> arr = {2, 3, 5};
    int target = 8;
    vector<int> combination;
    vector<vector<int>> ans;

    getCombination(arr, 0, combination, target, ans);

    for(const auto& row: ans){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }



    return 0;
}