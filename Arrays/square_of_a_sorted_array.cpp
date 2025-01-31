//Square of a sorted array
//Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number 
//sorted in non-decreasing order.
#include <iostream>
#include <cmath>
using namespace std;

void sortedSquares(int nums[], int size, int res[]) {
    int left = 0;
    int right = size - 1;
    
    for (int i = size - 1; i >= 0; i--) {
        if (abs(nums[left]) > abs(nums[right])) {
            res[i] = nums[left] * nums[left];
            left++;
        } else {
            res[i] = nums[right] * nums[right];
            right--;
        }
    }
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    int res[size];
    
    sortedSquares(nums, size, res);
    
    for (int i = 0; i < size; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}