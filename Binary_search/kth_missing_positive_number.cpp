// Kth missing positive number
// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Return the kth positive integer that is missing from this array.
// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
#include <iostream>
#include <vector>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size() - 1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int miss = arr[mid] - mid - 1;
        
        if (miss < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    return k + r + 1;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    
    cout << "The " << k << "th missing positive number is: " << findKthPositive(arr, k) << endl;
    
    return 0;
}