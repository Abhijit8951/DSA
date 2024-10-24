//Merge two sorted arrays
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m=3, n=3;
    int idx = m+n - 1, i = m-1, j = n-1;
    while(i >=0 && j>= 0){
        if(nums1[i] >= nums2[j]){
            nums1[idx] = nums1[i];
            idx--;
            i--;
        } else{
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
    while(j >= 0){
        nums1[idx] = nums2[j];
        idx--;
        j--;
    }

    for(int i=0;i<m+n;i++){
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}