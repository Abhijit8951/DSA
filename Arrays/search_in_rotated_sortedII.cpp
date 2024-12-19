#include <iostream>
#include <vector>
using namespace std;

bool isPresent(vector<int> &nums, int target){
    int st = 0, end = nums.size() - 1;

    while(st <= end){
        int mid = st + (end-st) / 2;
        if(nums[mid] == target) return true;

        if(nums[st] == nums[mid] && nums[mid] == nums[end]){
            st++; end--;
        } else if(nums[st] <= nums[mid]){
            if(nums[st <= target && target < nums[mid]]){
                end = mid - 1;
            } else{
                st = mid + 1;
            }
        } else{
            if(nums[mid] < target && target <= nums[end]){
                st = mid + 1;
            } else{
                end = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    cout << isPresent(nums, target) << endl;  //outputs 1 in case of true & 0 in case of false
    


    return 0;
}