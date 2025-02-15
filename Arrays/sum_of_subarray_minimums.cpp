//Sum of subarray minimums
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int sumSubarrayMins(std::vector<int>& nums) {
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;
    const int MOD = 1000000007;

    for (int i = 0; i < length; ++i) {
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = std::stack<int>();

    for (int i = length - 1; i >= 0; --i) {
        while (!stk.empty() && nums[stk.top()] > nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    long long sum = 0;

    for (int i = 0; i < length; ++i) {
        sum = (sum + static_cast<long long>(i - left[i]) * (right[i] - i) * nums[i] % MOD) % MOD;
    }

    return static_cast<int>(sum);
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    cout << sumSubarrayMins(nums) << std::endl;
    return 0;
}