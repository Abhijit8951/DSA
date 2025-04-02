// check Subset
// You are given two integer arrays ARR1 and ARR2 of length N and M respectively. You have to return true if ARR2 is a subset of ARR1, otherwise, return false.
// For Example:
// If the given arrays are [1, 2, 3] and [1, 2] then you need to return true as ARR2 is a subset of ARR1, but if the given arrays are [1, 2, 3] and [1, 2, 2] then you need to return false since ARR2 is not a subset of ARR1.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m) {
    unordered_map<int, int> freq;

    for (int num : arr1) {
        freq[num]++;
    }

    for (int num : arr2) {
        if (freq[num] == 0) {
            return false;
        }
        freq[num]--;
    }
    return true;
}

int main() {
    int n, m;
    cout << "Enter number of elements in first and second array: ";
    cin >> n >> m;
    
    vector<int> arr1(n), arr2(m);
    cout << "Enter " << n << " elements for first array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter " << m << " elements for second array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    if (checkSubset(arr1, arr2, n, m)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}