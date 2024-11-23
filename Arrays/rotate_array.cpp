//Rotate array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int n = nums.size();
    int k = 3;    //Number of steps to rotate
    k = k % n;    //Ensuring k is in the range of (0, n)

    reverse(nums.begin(), nums.end());   //reverse the entire array

    reverse(nums.begin(), nums.begin()+k);    //reverse first k elements

    reverse(nums.begin() + k, nums.end());    //reverse rest of elements after k

    for(int el : nums){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}