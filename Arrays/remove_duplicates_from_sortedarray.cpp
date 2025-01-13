//Remove duplicates from sorted array variation II(LC-80)
//Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each 
//unique element appears at most twice. The relative order of the elements should be kept the same.
//Since it is impossible to change the length of the array in some languages, you must instead have the
//result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
//Return k after placing the final result in the first k slots of nums.
//Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicate(vector<int> &nums){
    int k = 2;

    if(nums.size() <= 2)  return nums.size();

    for(int i=2; i<nums.size(); i++){
        if(nums[i] != nums[k-2]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

    cout << "Before removing duplicates: " << endl;
    for(int el : nums) {
        cout << el << " ";
    }
    cout << endl;

    int idx = removeDuplicate(nums);

    cout << "After removing duplicates: " << endl;
    for(int i=0; i<idx; i++){
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}