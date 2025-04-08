// Minimise the difference
// Problem statement
// You are given an array ‘A’ of length ‘N’ consisting only of positive integers and an integer ‘K’. You have to update every element of the array by increasing or decreasing its value by ‘K’ only once. Your task is to minimize the difference between maximum and minimum elements of the array after performing the increment or decrement on every element of the array.
// Note: After the operation, every value of the array should remain non-negative.
// For example:
// Let’s say the array ‘A’ = [1, 2, 3, 4, 5] and ‘K’ = 2, then after increasing each element by ‘K’. The array ‘A’ will become [3, 4, 5, 6, 7]. So the maximum - minimum will be 7 - 3 = 4. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimizeIt(vector<int> arr, int K) {
    int n = arr.size();
    if (n == 1) return 0;

    // Sort the array
    sort(arr.begin(), arr.end());

    // Initial difference between max and min
    int ans = arr[n - 1] - arr[0];

    int smallest = arr[0] + K;
    int largest = arr[n - 1] - K;

    for (int i = 0; i < n - 1; i++) {
        int minHeight = min(smallest, arr[i + 1] - K);
        int maxHeight = max(largest, arr[i] + K);

        if (minHeight < 0) continue;

        ans = min(ans, maxHeight - minHeight);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 15, 10};
    int K = 6;

    int result = minimizeIt(arr, K);
    cout << "Minimum difference: " << result << endl;

    return 0;
}