// Subarray sum zero
// You are given ‘N’ integers in the form of an array ‘ARR’. Count the number of subarrays having their sum as 0.
// For example :
// Let ‘ARR’ be: [1, 4, -5]
// The subarray [1, 4, -5] has a sum equal to 0. So the count is 1.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarrays(int n, vector<int> &arr) {
    unordered_map<int, int> prefixSumFreq;
    int currSum = 0, count = 0;

    prefixSumFreq[0] = 1; // To handle subarrays starting from index 0

    for (int i = 0; i < n; ++i) {
        currSum += arr[i];

        if (prefixSumFreq.find(currSum) != prefixSumFreq.end()) {
            count += prefixSumFreq[currSum];
        }

        prefixSumFreq[currSum]++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = countSubarrays(n, arr);
    cout << result << endl;

    return 0;
}