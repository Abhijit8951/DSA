//Top K frequent elements
//Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
//Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:
// Input: nums = [1], k = 1
// Output: [1]
#include<iostream>
#include<vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> getAns(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for(int num : nums) {
        freq[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(auto& [num, count] : freq) {
        pq.push({count, num});
        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> ans = getAns(nums, k);

    for(int el : ans) {
        cout << el << " ";
    }
    cout << endl;


    return 0;
}