// Find the Missing Number
// In an array of size n with elements from 1 to n+1, find the missing number.
#include <iostream>
#include <vector>
using namespace std;

int getMissing(vector<int>& nums, int n){
    int xorAll = 0, xorArray = 0;

    for(int i=1; i<=n+1; i++){
        xorAll = xorAll ^ i;
    }

    for(int val : nums){
        xorArray = xorArray ^ val;
    }

    return xorAll^xorArray;
}

int main(){
    vector<int> nums = {1, 2, 3, 5, 6, 7};
    int n = nums.size();

    cout << "The missing number is: " << getMissing(nums, n) << endl;


    return 0;
}