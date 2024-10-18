//Peak index in mountain array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {0, 3, 8, 9, 5, 2};
    int st=1, end=nums.size()-2;

    while(st <= end){
        int mid = st+(end - st)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
            cout << nums[mid] << endl;
        }

        if(nums[mid]<nums[mid+1]){
            st=mid+1;
        } else{
            end=mid-1;
        }
    }

    return 0;
}