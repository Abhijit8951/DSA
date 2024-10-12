//Program to find the max subarray sum using brute force approach
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 5;
    int arr[5] = {1, 2, 7, 4, -8};
    int maxSum = INT_MIN;

    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int end=st;end<n;end++){
            currSum+=arr[end];
            maxSum=max(currSum, maxSum);
        }
    }
    cout << "Max subarray sum: " << maxSum << endl;


    return 0;
}