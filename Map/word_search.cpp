// Word Search
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int k, int r, int c) {
    if (k == word.length()) return true;

    int rows = board.size();
    int cols = board[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || board[r][c] != word[k]) {
        return false;
    }

    visited[r][c] = true;

    bool found = dfs(board, visited, word, k + 1, r + 1, c) ||
                 dfs(board, visited, word, k + 1, r - 1, c) ||
                 dfs(board, visited, word, k + 1, r, c + 1) ||
                 dfs(board, visited, word, k + 1, r, c - 1);

    visited[r][c] = false;

    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Frequency count for early pruning
    int boardFreq[256] = {0};
    int wordFreq[256] = {0};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            boardFreq[board[r][c]]++;
        }
    }

    for (char ch : word) {
        wordFreq[ch]++;
    }

    for (char ch : word) {
        if (wordFreq[ch] > boardFreq[ch]) return false;
    }

    if (wordFreq[word[0]] > wordFreq[word[word.length() - 1]]) {
        reverse(word.begin(), word.end());
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (dfs(board, visited, word, 0, r, c)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    if (exist(board, word)) {
        cout << "Word found!" << endl;
    } else {
        cout << "Word not found." << endl;
    }

    return 0;
}