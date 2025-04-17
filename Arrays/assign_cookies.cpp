// Assign cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sort both arrays
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = g.size(); // Number of children
    int m = s.size(); // Number of cookies
    int count = 0;    // Count of content children
    int i = 0;        // Pointer for greed array
    int j = 0;        // Pointer for size array

    // Loop through both arrays
    while (i < n && j < m) {
        if (s[j] >= g[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }

    return count;
}

int main() {
    // Example input
    vector<int> greed = {1, 2, 3};
    vector<int> cookies = {1, 1};

    int result = findContentChildren(greed, cookies);

    cout << "Number of content children: " << result << endl;

    return 0;
}