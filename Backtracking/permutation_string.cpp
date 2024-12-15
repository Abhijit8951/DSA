//Print all the permutations of a string
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getPermutation(string& str, int idx, vector<string>& ans) {
    if (idx == str.size()) {
        ans.push_back(str);
        return;
    }

    for (int i = idx; i < str.size(); i++) {
        swap(str[idx], str[i]);
        getPermutation(str, idx + 1, ans);
        swap(str[idx], str[i]); // Backtrack to the original string
    }
}

int main() {
    string str = "abc";
    vector<string> ans;

    getPermutation(str, 0, ans);

    // Print all permutations
    for (const auto& permutation : ans) {
        cout << permutation << endl;
    }

    return 0;
}