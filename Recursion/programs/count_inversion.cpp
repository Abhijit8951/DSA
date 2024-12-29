//Count Inversions
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid+1;
    int invCount = 0;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=end){
        temp.push_back(arr[j]);
        j++;
        invCount += (mid - i + 1);
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }
    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end-st)/2;

        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid+1, end);

        int invCount = merge(arr, st, mid, end);

        return leftInvCount+rightInvCount+invCount;
    }
    return 0;
}

int main(){
    vector<int> nums = {6, 3, 5, 2, 7};

    int res = mergeSort(nums, 0, nums.size()-1);
    

    // Brute Force
    // int count = 0;
    // for(int i=0; i<nums.size()-1; i++){
    //     for(int j=i+1; j<nums.size(); j++){
    //         if(nums[i] > nums[j]){
    //             count++;
    //         }
    //     }
    // }

    cout << "The number of inversions are: " << res << endl;


    return 0;
}