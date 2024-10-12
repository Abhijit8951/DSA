#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target){
    vector<int> ans;
    int size=nums.size();
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
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