//Book allocation problem
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr,int n,int m,int maxallowedPages){
    int student=1,pages=0; 

    for(int i=0;i<n;i++){
        if(arr[i]>maxallowedPages){
            return false;
        }

        if(pages + arr[i] <= maxallowedPages){
            pages += arr[i];
        } else{
            student++;
            pages=arr[i];
        }
    }

    return student > m ? false : true;
}

int allocateBooks(vector<int> &arr,int n,int m){
    if(m > n){
        return -1;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int ans=-1;
    int st=0, end=sum;
    while(st <= end){
        int mid = st+(end-st)/2;

        if(isValid(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        } else{
            st=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 1, 3, 4};
    int n=4, m=2;

    cout << allocateBooks(arr, n, m) << endl;

    return 0;
}