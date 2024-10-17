//Binary search
#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int> nums, int target){
    int st=0, end=nums.size()-1;

    while(st <= end){
        int mid = st + (end - st)/2;
        if(target < nums[mid]){
            end = mid-1;
        } else if(target > nums[mid]){
            st = mid+1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {0, 2, 4, 6, 8, 10};
    int target=8;
    cout << binarysearch(nums, target) << endl;

    return 0;
}