// Kth Smallest and Largest Element of Array
// Problem statement
// You are given an array ‘Arr’ consisting of ‘N’ distinct integers and a positive integer ‘K’. Find out Kth smallest and Kth largest element of the array. It is guaranteed that K is not greater than the size of the array.
// Example:
// Let ‘N’ = 4,  ‘Arr’ be [1, 2, 5, 4] and ‘K’ = 3.  
// then the elements of this array in ascending order is [1, 2, 4, 5].  Clearly, the 3rd smallest and largest element of this array is 4 and 2 respectively.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k) {
    vector<int> ans;

    sort(arr.begin(), arr.end());
    ans.push_back(arr[k - 1]);          // k-th smallest
    ans.push_back(arr[n - k]);          // k-th largest

    return ans;
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int n = arr.size();
    int k = 3;

    vector<int> result = kthSmallLarge(arr, n, k);

    cout << "K-th Smallest: " << result[0] << endl;
    cout << "K-th Largest: " << result[1] << endl;

    return 0;
}
