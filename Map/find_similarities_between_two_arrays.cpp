// Find similarities between two arrays.
// You have been given two arrays/list ‘ARR1’ and ‘ARR2’ consisting of ‘N’ and ‘M’ integers respectively. Your task is to return the number of elements common to ‘ARR1’ and ‘ARR2’ and the number of elements in the union of ‘ARR1’ and ‘ARR2’.
// Example:
// Let’s assume ‘ARR1’ is [1,2,3,4,5] and ‘ARR2’ is [2,4,6,8]. Elements common to ‘ARR1’ and ‘ARR2’ are [2,4] as they occur in both ‘ARR1’ and ‘ARR2’. Therefore the number of elements common to ‘ARR1’ and ‘ARR2’ is 2. Union of ‘ARR1’ and ‘ARR2’ is [1,2,3,4,5,6,8]. Therefore the number of distinct elements in the union of ‘ARR1’ and ‘ARR2’ is 7. So, the answer will be 2 7.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

pair<int, int> findSimilarity(vector<int>& arr1, vector<int>& arr2, int n, int m) 
{
    unordered_set<int> set1(arr1.begin(), arr1.end());  // Convert arr1 to unordered_set
    unordered_set<int> set2(arr2.begin(), arr2.end());  // Convert arr2 to unordered_set

    int commonCount = 0;

    // Find common elements between set1 and set2
    for (int num : set1) {
        if (set2.find(num) != set2.end()) {
            commonCount++;  // Element is common
        }
    }

    // Union of two sets (combining both sets)
    unordered_set<int> unionSet = set1;  // Start with set1
    unionSet.insert(set2.begin(), set2.end());  // Insert elements of set2 into unionSet

    // The size of the union is the number of distinct elements in both sets
    int unionSize = unionSet.size();

    return make_pair(commonCount, unionSize);
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 3, 4};

    pair<int, int> result = findSimilarity(arr1, arr2, arr1.size(), arr2.size());

    cout << "Common count: " << result.first << endl;
    cout << "Union count: " << result.second << endl;

    return 0;
}