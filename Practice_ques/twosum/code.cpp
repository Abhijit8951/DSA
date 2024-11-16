//Two sum
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> nums = {-1,  0, 1, 2, -1, 4};
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;
    int i=0, j=n-1;

    while(i < j){
        // if(i > 0 && nums[i] == nums[i-1]) continue;
        int sum = nums[i] + nums[j];

        if(sum < 0){
            i++;
        } else if(sum > 0){
            j--;
        } else{
            ans.push_back({nums[i], nums[j]});
            int current_i = nums[i];
            int current_j = nums[j];
            while (i < j && nums[i] == current_i) i++;
            while (i < j && nums[j] == current_j) j--;
        }
    }

    for (const auto& el : ans) {
        cout << el[0] << "," << el[1] << endl;
    }

    return 0;

}