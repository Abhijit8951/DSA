// Range sum query
// Given an integer array nums, handle multiple queries of the following type:
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int prefixSum[MAX_SIZE + 1];

void buildPrefixSum(int nums[], int n) {
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
}

int sumRange(int left, int right) {
    return prefixSum[right + 1] - prefixSum[left];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int nums[MAX_SIZE];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    buildPrefixSum(nums, n);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int left, right;
        cout << "Enter range (left right): ";
        cin >> left >> right;
        cout << "Sum from " << left << " to " << right << " is: "
             << sumRange(left, right) << endl;
    }

    return 0;
}