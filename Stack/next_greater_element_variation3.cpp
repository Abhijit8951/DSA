//Next greater element (LC: 503)
//Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you 
//could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
//Input: nums = [1,2,1]
// Output: [2,-1,2]
// Explanation: The first 1's next greater number is 2; 
// The number 2 can't find next greater number. 
// The second 1's next greater number needs to search circularly, which is also 2.
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for(int i=2*n; i>=0; i--) {
        while(s.size() > 0 && nums[s.top()] <= nums[i%n]) {
            s.pop();
        }

        ans[i%n] = s.empty() ? -1 : nums[s.top()];
        s.push(i%n);
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 3};

    vector<int> ans = nextGreaterElements(nums);
    for(int el : ans) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}