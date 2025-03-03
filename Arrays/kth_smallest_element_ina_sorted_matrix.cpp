// Kth smallest elementt in a sorted matrix
//Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
// Note that it is the kth smallest element in the sorted order, not the kth distinct element.
// You must find a solution with a memory complexity better than O(n2).
// Example 1:
// Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
// Output: 13
// Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
#include<iostream>
#include<vector>
using namespace std;

int findAns(vector<vector<int>> matrix, int k) {
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> ans;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            ans.push_back(matrix[i][j]);
        }
    }

    sort(ans.begin(), ans.end());

    return ans[k-1];
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    int num = findAns(matrix, k);

    cout << num << endl;

    return 0;
}