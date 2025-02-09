#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(const vector<int>& heights, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(const vector<int>& heights, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(const vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = 0;
    for (int i = 0; i < n; i++) {
        if (next[i] == -1) {
            next[i] = n;
        }
        int width = next[i] - prev[i] - 1;
        int newArea = heights[i] * width;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(const vector<vector<int>>& mat) {
    if (mat.empty()) return 0;
    int n = mat.size(), m = mat[0].size();
    vector<int> heights(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) 
                heights[j] = 0;
            else 
                heights[j] += 1;
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    cout << "Maximum area of rectangle with 1's: " << maxArea(mat) << endl;
    return 0;
}