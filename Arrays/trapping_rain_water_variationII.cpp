// Trapping rain water(LC: 42)
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = height.size();
    vector<int> lmax(n, 0);
    vector<int> rmax(n, 0);
    int ans = 0;

    lmax[0] = height[0];
    rmax[n-1] = height[n-1];

    for(int i=1; i<n; i++) {
        lmax[i] = max(lmax[i-1], height[i]);
    }

    for(int i=n-2; i>0; i--) {
        rmax[i] = max(rmax[i+1], height[i]);
    }

    for(int i=0; i<n; i++) {
        ans += min(lmax[i], rmax[i]) - height[i];
    }

    cout << ans << " units of water can be trapped" << endl;

    return 0;
}