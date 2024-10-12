#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target){
    vector<int> ans;
    int size=nums.size();
    int i=0, j=size-1;
    while(i<j){
        int pairsum = nums[i]+nums[j];
        if(pairsum < target){
            i++;
        } else if(pairsum > target){
            j--;
        } else{
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {2, 9, 11, 4, 7};
    int target = 13;

    vector<int> ans = pairsum(nums, target);
    cout << ans[0] << " , " << ans[1] << endl;

    return 0;
}