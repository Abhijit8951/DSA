// Find pivot element
#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int>& nums){
    int totalSum = 0;
    for(int el : nums){
        totalSum += el;
    }

    int leftSum = 0;
    for(int i=0;i<nums.size();i++){
        int rightSum = totalSum - leftSum - nums[i];

        if(leftSum == rightSum){
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = findPivot(nums);
    cout << "The pivot index is: " << result << endl;

    return 0;
}