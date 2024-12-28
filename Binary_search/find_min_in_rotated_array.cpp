//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, 
//the array nums = [0,1,2,4,5,6,7] might become:
// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
//Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 4, 5, 1, 2};
    int st = 0, end = nums.size()-1;

    while(st < end){
        int mid = st + (end-st)/2;

        if(nums[mid]>nums[end]){
            st = mid+1;
        } else {
            end = mid;
        }
    }
    cout << "The minimum is : " << nums[st] << endl;

    return 0;
}