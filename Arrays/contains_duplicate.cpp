//Given an integer array nums and an integer k, return true if there are two distinct indices i and j in 
//the array such that nums[i] == nums[j] and abs(i - j) <= k.
// Input: nums = [1,2,3,1], k = 3
// Output: true
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> nums, int k){
    unordered_map<int,int> mp;
    int n = nums.size();
    
    for(int i=0; i<n; i++){
        if(mp.count(nums[i])){
            if(abs(i-mp[nums[i]])<=k) return true;
        }
        mp[nums[i]] = i;
    }
    return false;

}

int main(){
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    cout << containsDuplicate(nums, k) << endl;


    return 0;
}