#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Horizontal
    for (int j = 0; j < n; j++) {
        if (board[row][j] == 'Q') {
            return false;
        }
    }

    // Vertical
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Left Diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Right Diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void nQueen(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q'; // Place queen
            nQueen(board, row + 1, n, ans);
            board[row][j] = '.'; // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;

    nQueen(board, 0, n, ans);

    return ans;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> results = solveNQueens(n);

    cout << "Number of solutions: " << results.size() << endl;
    for (const auto& solution : results) {
        cout << "Solution:" << endl;
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}