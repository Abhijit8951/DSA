//Find the Duplicate Number
//Given an array of n+1 integers where each integer is between 1 and n, find the duplicate.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int getDuplicate(vector<int>& nums){
    unordered_set<int> check;

    for(int val : nums){
        if(check.count(val)){
            return val;
        }
        check.insert(val);
    }
    return -1;
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 4, 5};

    cout << getDuplicate(nums) << endl;


    return 0;
}