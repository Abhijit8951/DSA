//A sudoku solution must satisfy all of the following rules:

// 1. A sudoku solution must satisfy all of the following rules:
// 2. Each of the digits 1-9 must occur exactly once in each row.
// 3. Each of the digits 1-9 must occur exactly once in each column.
// 4. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// 5. The '.' character indicates empty cells.

#include <vector>
#include <iostream>
using namespace std;

void solveSudoku(vector<vector<char>>& board);
bool solve(vector<vector<char>>& board);
bool isValid(const vector<vector<char>>& board, int row, int col, char num);

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);

    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board);
}

bool solve(vector<vector<char>>& board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solve(board)) {
                            return true;
                        }

                        board[row][col] = '.'; // Backtrack
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // Solved
}

bool isValid(const vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; ++i) {
        // Check row and column
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }

        // Check 3x3 sub-box
        int boxRow = 3 * (row / 3) + i / 3;
        int boxCol = 3 * (col / 3) + i % 3;
        if (board[boxRow][boxCol] == num) {
            return false;
        }
    }
    return true;
}
