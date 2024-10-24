//find next permutation
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3};
    int pivot = -1, n = nums.size();
    for(int i = n-2;i>=0;i--){
        if(nums[i] < nums[i+1]){
            pivot = i;
            break;
        }
    }

    if(pivot == -1){
        reverse(nums.begin(), nums.end());
        // return;
    }

    for(int i=n-1;i>pivot;i--){
        if(nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    reverse(nums.begin() + pivot + 1, nums.end());

    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }


    return 0;
}