//Add two arrays
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums1 = {1, 2, 6, 9};
    vector<int> nums2 = {4, 7, 1};
    int i = nums1.size() - 1;
    int j = nums2.size() - 1;
    vector<int> ans;
    int carry = 0;

    while(i >= 0 && j >= 0){
        int sum = nums1[i] + nums2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--; j--;
    }

    while(i >= 0){
        int sum = nums1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }

     while(j >= 0){
        int sum = nums2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }


    reverse(ans.begin(), ans.end());
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;



    return 0;
}