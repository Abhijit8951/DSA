//Check if an arrray is sorted or not(Recursion)
#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int> nums, int n){
    if(n == 0 || n == 1){
        return true;
    }

    return nums[n-1] >= nums[n-1] && isSorted(nums, n-1);
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << isSorted(nums, nums.size()) << endl;


    return 0;
}