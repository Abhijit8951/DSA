//Sort an array with 0s, 1s, 2s using optimised approach
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};
    int n = arr.size();
    int count0=0, count1=0, count2=0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }

    int idx=0;
    for(int i=0;i<count0;i++){
        arr[idx] = 0;
        idx++;
    }
    for(int i=0;i<count1;i++){
        arr[idx] = 1;
        idx++;
    }
    for(int i=0;i<count2;i++){
        arr[idx] = 2;
        idx++;
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }


    return 0;
}