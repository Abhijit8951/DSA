//Find the product of the  array except self using brute-force approach
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4}, ans;
    int prod;
    for(int  i=0;i<nums.size();i++){
        prod=1;
        for(int j=0;j<nums.size();j++){
            if(i != j){
                prod*=nums[j];
            }
        }
        ans.push_back(prod);
    }
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }

    return 0;
}