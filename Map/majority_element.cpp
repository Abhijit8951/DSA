// Majority Element
// You are given an array ‘ARR’ and another integer number ‘K’. Your task is to find the all elements of ‘ARR’ which occur more than or equals to ‘N/K’ times in ‘ARR’ and ‘N’ is the length of array ‘ARR’.
// For example:
// Given array ‘ARR = { 1, 2, 3, 3, 3, 3, 4, 4, 4, 1, 2 ,0}’ and ‘K = 4’
// Answer is {3, 4} because ‘3’ occurs ‘4’ times and ‘4’ occurs ‘3’ times which is more than or equals to ‘12/ 4 =3’.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countTheNumber(std::vector<int> &arr, int n, int k) {
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++) {
        m[arr[i]]++;
    }

    vector<int> ans;

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second >= n / k) {
            ans.push_back(it->first);
        }
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter number of elements and divisor: ";
    cin >> n >> k;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = countTheNumber(arr, n, k);
    
    cout << "Elements occurring at least n/k times: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << std::endl;

    return 0;
}