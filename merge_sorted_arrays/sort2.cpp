#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    vector<int> temp;
    int i = 0, j = 0;

    while(i <= m-1 && j <= n-1){
        if(nums1[i] <= nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        } else{
            temp.push_back(nums2[j]);
            j++;
        }
    }

    while( j <= n-1){
        temp.push_back(nums2[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        nums1[idx] = temp[idx];
    }
}

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0, 0};
    vector<int> nums2 = {5, 6, 7, 8};
    int m = 3, n = 4;

    merge(nums1, m, nums2, n);

    for(int val : nums1){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}