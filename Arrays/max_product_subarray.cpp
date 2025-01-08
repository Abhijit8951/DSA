//Maximum product subarray
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int pre = 1;
    int post = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (post == 0) post = 1;
        pre = pre * nums[i];
        post = post * nums[n - i - 1];
        ans = max({pre, post, ans});
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << "The maximum product of a subarray is: " << result << endl;

    return 0;
}
