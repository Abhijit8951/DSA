//Painter partition problem
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int MaxAllowedTime){
    int painters=1, time=0;

    for(int i=0;i<n;i++){
        if(time + arr[i] <= MaxAllowedTime){
            time += arr[i];
        } else{
            painters++;
            time=arr[i];
        }
    }
    return painters > m ? false : true;
}

int minTimeToPaint(vector<int> &arr, int n, int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int st=0, end=sum, ans=-1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        } else{
            st=mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {40, 30, 10, 20};
    int n=4, m=2;

    cout << minTimeToPaint(arr,n,m) << endl;

    return 0;
}