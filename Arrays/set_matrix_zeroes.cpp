// Set matrix zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
#include <iostream>
using namespace std;

const int MAX = 100; // maximum size of the matrix

void setZeroes(int matrix[MAX][MAX], int n, int m) {
    int rowFlags[MAX] = {0}; // flags for rows
    int colFlags[MAX] = {0}; // flags for columns

    // First pass to find which rows and columns need to be zeroed
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                rowFlags[i] = 1;
                colFlags[j] = 1;
            }
        }
    }

    // Second pass to update the matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(rowFlags[i] || colFlags[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    int matrix[MAX][MAX];

    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    printMatrix(matrix, n, m);

    setZeroes(matrix, n, m);

    cout << "\nModified Matrix:\n";
    printMatrix(matrix, n, m);

    return 0;
}