//Next greater element variation II  LC: 496
//The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
//Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    unordered_map<int, int> m;
    stack<int> s;

    for(int i=nums2.size()-1; i>=0; i--) {
        while(s.size()>0 && s.top() <= nums2[i]) {
            s.pop();
        }

        if(s.empty()) {
            m[nums2[i]] = -1;
        } else {
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }

    vector<int> ans;
    for(int i=0; i<nums1.size(); i++) {
        ans.push_back(m[nums1[i]]);
    }

    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}