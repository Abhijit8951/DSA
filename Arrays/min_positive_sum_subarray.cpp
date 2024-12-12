//You are given an integer array nums and two integers l and r. Your task 
//is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.

//Return the minimum sum of such a subarray. If no such subarray exists, return -1.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    vector<int> nums = {3, -2, 1, 4};
    int l = 2, r = 3;

    int mini = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size() && j - i + 1 <= r; j++) {
            sum += nums[j]; 
            int len = j-i+1;
            if (len>=l&&sum>0) {
                mini=min(mini,sum);

            }
        }
    }

    if(mini != INT_MAX){
        cout << mini << endl;
    } else {
        cout << -1 << endl;
    }


    return 0;
}