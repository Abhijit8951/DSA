//Intersection Of Two Arrays
//Given two integer arrays nums1 and nums2, return an array of their intersection
//Each element in the result must be unique and you may return the result in any order.
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>
using namespace std;

int main(){
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    unordered_set<int> s1;
    unordered_set<int> s2;
    vector<int> ans;

    for(int i=0; i<nums1.size(); i++){
        if(s1.find(nums1[i]) == s1.end()){
            s1.insert(nums1[i]);
        }
    }

    for(int i=0; i<nums2.size(); i++){
        if(s2.find(nums2[i]) == s2.end()){
            s2.insert(nums2[i]);
        }
    }

    for(int el : s1){
        for(int val : s2){
            if(el == val){
                ans.push_back(el);
            }
        }
    }

    for(int el : ans){
        cout << el << " ";
    }
    cout << endl;



    return 0;
}