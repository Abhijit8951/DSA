// Number of equivalent Domino pair
// Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
// Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].
#include <iostream>
#include <vector>
#include <algorithm> // for min and max
using namespace std;

int numEquivDominoPairs(const vector<vector<int>>& dominoes) {
    int count[100] = {0};
    int res = 0;
    for (const auto& d : dominoes) {
        int a = min(d[0], d[1]);
        int b = max(d[0], d[1]);
        int key = a * 10 + b;
        res += count[key];
        count[key]++;
    }
    return res;
}

int main() {
    // Predefined input
    vector<vector<int>> dominoes = {
        {1, 2},
        {2, 1},
        {3, 4},
        {5, 6}
    };

    int result = numEquivDominoPairs(dominoes);
    cout << "Number of equivalent domino pairs: " << result << endl;

    return 0;
}