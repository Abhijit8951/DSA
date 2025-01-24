//Number of good pairs (LC-1512)
//Given an array of integers nums, return the number of good pairs.
// A pair (i, j) is called good if nums[i] == nums[j] and i < j.
#include<iostream>
#include<vector>
using namespace std;

int getAns(vector<int> nums) {
    int count = 0;
    int n = nums.size();

    if(n > 1){
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    int res = getAns(nums);
    cout << "The number of good pairs is: " << res << endl;


    return 0;
}