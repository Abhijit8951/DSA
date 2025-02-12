//Pascal's Triangle (LC-118)
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    // Base case
    if (numRows == 1) return {{1}};
    
    // Recursive call for the previous rows
    vector<vector<int>> triangle = generatePascal(numRows - 1);
    
    // Generate the current row based on the last row
    vector<int> prevRow = triangle.back();
    vector<int> newRow(numRows, 1); // First and last elements are always 1
    
    // Fill the middle elements using the sum of two elements from the previous row
    for (int i = 1; i < numRows - 1; i++) {
        newRow[i] = prevRow[i - 1] + prevRow[i];
    }
    
    triangle.push_back(newRow);
    
    return triangle;
}

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows = 5;
    vector<vector<int>> result = generatePascal(numRows);
    
    printTriangle(result);
    
    return 0;
}