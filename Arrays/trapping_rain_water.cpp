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
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int n = height.size();
    int ans = 0;
    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;

    while(l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if(lmax < rmax) {
            ans += lmax - height[l];
            l++;
        } else {
            ans += rmax - height[r];
            r--;
        }
    }

    cout << ans << " units of water can be trapped" << endl;

    return 0;
}