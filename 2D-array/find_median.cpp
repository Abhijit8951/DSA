// Find Median
// Given a row-wise sorted matrix having N number of rows and M number of columns. Your task is to find the median of the given matrix.
// Note :
// Assume that the size of the matrix N*M is always odd.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to count elements less than or equal to target in a row
int countLessEqual(const vector<int>& row, int target) {
    return upper_bound(row.begin(), row.end(), target) - row.begin();
}

// Function to find the median in a row-wise sorted matrix
int findMedian(vector<vector<int>>& matrix, int N, int M) {
    int low = matrix[0][0], high = matrix[0][M - 1];

    // Find global min and max values from the matrix
    for (int i = 1; i < N; ++i) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][M - 1]);
    }

    int desired = (N * M + 1) / 2;

    // Binary search to find the median
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            count += countLessEqual(matrix[i], mid);
        }

        if (count < desired) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    int N, M;
    cout << "Enter number of rows (N): ";
    cin >> N;
    cout << "Enter number of columns (M): ";
    cin >> M;

    vector<vector<int>> matrix(N, vector<int>(M));

    cout << "Enter matrix elements (row-wise sorted):\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> matrix[i][j];
        }
    }

    int median = findMedian(matrix, N, M);
    cout << "Median of the matrix is: " << median << endl;

    return 0;
}