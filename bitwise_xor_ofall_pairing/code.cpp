//Bitwise XOR of all pairing
//You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. 
//There exists another array, nums3, which contains the bitwise XOR of all pairings of integers 
//between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).]
//Return the bitwise XOR of all integers in nums3.
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {10, 2, 5, 0};
    int c1 = nums1.size();
    int c2 = nums2.size();
    int x1 = 0, x2 = 0;

    if(c1%2 != 0){
        for(int el : nums2){
            x2 ^= el;
        }
    }

    if(c2%2 != 0){
        for(int el : nums1){
            x1 ^= el;
        }
    }

    cout << (x1^x2) << endl;


    return 0;
}