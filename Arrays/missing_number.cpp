//Given an array nums containing n distinct numbers in the range [0, n], 
//return the only number in the range that is missing from the array.
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
// 2 is the missing number in the range since it does not appear in nums.
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 0, 1};
    int n = nums.size();
    int actualSum=0, currSum=0, res;

    for(int i=1; i<=n; i++){
        actualSum += i;
    }

    for(int el : nums){
        currSum += el;
    }

    res = actualSum-currSum;
    cout << "The missing number is: " << res << endl;


    return 0;
}