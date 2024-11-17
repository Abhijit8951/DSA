#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

int main() {
    vector<int> nums = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; 
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
            int p = j + 1, q = n - 1;
            while (p < q) {
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                if (sum < target) {
                    p++;
                } else if (sum > target) {
                    q--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    while (p < q && nums[p] == nums[p - 1]) p++;
                }
            }
        }
    }

    for (const auto& el : ans) {
        cout << "[" << el[0] << "," << el[1] << "," << el[2] << "," << el[3] << "]" << endl;
    }

    return 0;
}
