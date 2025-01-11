//Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
//find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and 
//numbers[index2] where 1 <= index1 < index2 <= numbers.length.
//Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
#include <iostream>
using namespace std;

int* twoSum(int nums[], int size, int target) {
    int st = 0;
    int end = size - 1;

    while (st < end) {
        int sum = nums[st] + nums[end];

        if (sum > target) {
            end--;
        } else if (sum < target) {
            st++;
        } else {
            int* result = new int[2];
            result[0] = st + 1;
            result[1] = end + 1;
            return result;
        }
    }

    return nullptr;
}

int main() {
    int nums[] = {2, 7, 11, 15}; 
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    int* result = twoSum(nums, size, target);

    if (result != nullptr) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
        delete[] result;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
