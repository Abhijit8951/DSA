//Program to find the max subarray sum using Kadane's Algorithm
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 8;
    int arr[8] = {3, 1, -5, 3, 8, -1, 3, -4};
    int currSum = 0,maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        maxSum=max(currSum, maxSum);
        if(currSum < 0){
            currSum=0;
        }
    }
    cout << "Maximum subarray sum: " << maxSum << endl;


    return 0;
}