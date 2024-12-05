//Plus one
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 6, 9};
    int carry = 1;
    vector<int> ans;

    for(int i = nums.size()-1; i>=0; i--){
        int sum = nums[i] + carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum%10);
    }

    if(carry == 1){
        ans.push_back(1);
    }

    reverse(ans.begin(), ans.end());
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;



    return 0;
}