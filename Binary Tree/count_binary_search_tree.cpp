// Count unique binary search tree
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
#include <iostream>
#include <vector>
using namespace std;

// Function to compute the number of unique BSTs
int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Number of unique BSTs: " << numTrees(n) << endl;
    return 0;
}
