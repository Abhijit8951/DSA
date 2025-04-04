// 132 Pattern
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
// Return true if there is a 132 pattern in nums, otherwise, return false.
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    int num3 = INT_MIN;
    
    for (int i = n - 1; i >= 0; i--) {
        if (nums[i] < num3) return true;
        
        while (!st.empty() && st.top() < nums[i]) {
            num3 = st.top();
            st.pop();
        }
        
        st.push(nums[i]);
    }
    
    return false;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (find132pattern(nums)) {
        cout << "132 pattern found\n";
    } else {
        cout << "132 pattern not found\n";
    }

    return 0;
}