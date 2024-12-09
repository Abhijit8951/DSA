//Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = nums.size();
    int cols = nums[0].size();
    vector<int> ans;

    for(int i=0; i<cols; i++){
        if(i&1){
            for(int j=rows-1; j>=0; j--){
                ans.push_back(nums[j][i]);
            }
        } else{
            for(int j=0; j<rows; j++){
                ans.push_back(nums[j][i]);
            }
        }
    }

    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}