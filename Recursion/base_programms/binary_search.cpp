//Binary search using recursion
#include <iostream>
#include <vector>
using namespace std;

int binSearch(vector<int>& nums, int target, int st, int end) {
    if(st <= end){
        int mid = st + (end - st) / 2;
        if(nums[mid] == target) return mid;

        if(nums[mid] < target) return binSearch(nums, target, mid+1, end);

        if(nums[mid] > target) return binSearch(nums, target, st, mid-1);
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    int st = 0, end = nums.size() - 1;

    cout << binSearch(nums, target, st, end) << endl;

    return 0;
    
}