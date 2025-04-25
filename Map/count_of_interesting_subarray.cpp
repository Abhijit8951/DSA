// Count of interesti ng subarray
// You are given a 0-indexed integer array nums, an integer modulo, and an integer k.
// Your task is to find the count of subarrays that are interesting.
// A subarray nums[l..r] is interesting if the following condition holds:
// Let cnt be the number of indices i in the range [l, r] such that nums[i] % modulo == k. Then, cnt % modulo == k.
// Return an integer denoting the count of interesting subarrays.
// Note: A subarray is a contiguous non-empty sequence of elements within an array.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
    unordered_map<long long, long long> mp;
    long long ans = 0, prefix = 0, n = nums.size();
    mp[0]++;

    for (int i = 0; i < n; i++) {
        if (nums[i] % mod == k)
            prefix++;
        prefix %= mod;

        if (mp.find((prefix - k + mod) % mod) != mp.end())
            ans += mp[(prefix - k + mod) % mod];

        mp[prefix]++;
    }
    return ans;
}

int main() {
    int n, mod, k;

    // Input size of array
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Input mod and k
    cout << "Enter mod and k: ";
    cin >> mod >> k;

    // Call the function and print result
    long long result = countInterestingSubarrays(nums, mod, k);
    cout << "Count of interesting subarrays: " << result << endl;

    return 0;
}