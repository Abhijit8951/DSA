//Find the product of the  array except self using optimal approach
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();
    vector<int> ans(n, 1);
    //Forward
    for(int i=1;i<n;i++){
        ans[i] = ans[i-1] * nums[i-1];
    }

    //Reverse
    int right =1;
    for(int i=n-1;i>=0;i--){
        ans[i] *= right;
        right *= nums[i];
    }

    //Print Answer
    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}