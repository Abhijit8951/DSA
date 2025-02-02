//Find winner of tictactoe game
//Example 1:
// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: A wins, they always play first.
// Example 2:
// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: B wins.
#include <iostream>
#include <vector>

using namespace std;

string checkWinners(vector<char> &matrix) {
    vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    
    for (auto pattern : winPatterns) {
        int i = pattern[0], j = pattern[1], k = pattern[2];
        if (matrix[i] != 0 && matrix[i] == matrix[j] && matrix[i] == matrix[k]) {
            return string(1, matrix[i]);
        }
    }
    return "";
}

string tictactoe(vector<vector<int>> &moves) {
    vector<char> matrix(9, 0);
    bool Alice = true;
    string ans;
    
    for (auto move : moves) {
        int index = (move[0] * 3) + move[1];
        matrix[index] = (Alice ? 'A' : 'B');
        Alice = !Alice;
        ans = checkWinners(matrix);
        if (!ans.empty()) return ans;
    }
    
    for (int i = 0; i < 9; i++) {
        if (matrix[i] == 0) return "Pending";
    }
    
    return "Draw";
}

int main() {
    vector<vector<int>> moves = {{0,0}, {2,0}, {1,1}, {2,1}, {2,2}};
    cout << tictactoe(moves) << endl;
    return 0;
}
