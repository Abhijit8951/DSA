//First negative in every window of size k
//Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.
// Note: If a window does not contain a negative integer, then return 0 for that window.
// Examples:
// Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
// Output: [-8, 0, -6, -6]
// Explanation:
// Window {-8, 2}: First negative integer is -8.
// Window {2, 3}: No negative integers, output is 0.
// Window {3, -6}: First negative integer is -6.
// Window {-6, 10}: First negative integer is -6.
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;
    
    for(int i = 0; i < k; i++) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }
    
    if(!dq.empty()) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }
    
    for(int i = k; i <= n; i++) {
        if(!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }
        
        if(arr[i] < 0) {
            dq.push_back(i);
        }
        
        if(!dq.empty()) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    
    vector<int> result = FirstNegativeInteger(arr, k);
    
    cout << "First negative integer in each window of size " << k << ": ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}