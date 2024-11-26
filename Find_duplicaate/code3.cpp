//Find duplicate elements from an array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;

    sort(nums.begin(), nums.end());

    for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]){
            ans.push_back(nums[i]);
        }
    }

    for(int el : ans){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}