//swap alternatives
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int n = nums.size();

    // int i=0, j=i+1;
    // while(i<n-1 && j<n){
    //     swap(nums[i], nums[j]);
    //     i+=2; j+=2;
    // }

    for(int i=0;i<n;i+=2){
        if(i+1 < n){
            swap(nums[i], nums[i+1]);
        }
    }

    for(int el : nums){
        cout << el << endl;
    }


    return 0;
}