#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3};
    vector<int>res;
    int sum = 0;
    int carry = 1;
    for(int i=nums.size()-1;i>=0;i--){
        sum=0;
        sum = nums[i]+carry;
        res.push_back(sum%10);
        carry = sum/10;
    }
    if(carry == 1){
        res.push_back(1);
    }
    reverse(res.begin(),res.end());
    for(int val : res){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}