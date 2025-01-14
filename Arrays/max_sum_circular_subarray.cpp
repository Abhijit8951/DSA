//Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. Formally, the next element 
//of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at most once. Formally, for 
//a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
#include <iostream>
#include <vector>
using namespace std;

int findRes(vector<int> nums){
    int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
    for(int i : nums) {
        total_sum+=i; curr_sum1+=i; curr_sum2+=i;
        mxsum_subary=max(mxsum_subary,curr_sum1);
        if(curr_sum1<0) curr_sum1=0;
        minsum_subary=min(curr_sum2,minsum_subary);
        if(curr_sum2>0) curr_sum2=0;
    }
    return (total_sum==minsum_subary) ? mxsum_subary : max(mxsum_subary,total_sum-minsum_subary);
}

int main(){
    vector<int> nums = {1, -2, 3, -2};
    int res = findRes(nums);

    cout << "The maximum sum is: " << res << endl;


    return 0;
}