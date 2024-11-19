//Pair sum
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {2, 9, 11, 4, 7};
    int target = 13;
    vector<pair<int, int>> ans;

    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i] + nums[j] == target){
                ans.push_back({nums[i], nums[j]});
            }
        }
    }

    for(auto el : ans){
        cout << el.first << " " << el.second << endl;
    }


    return 0;
}