//Program to find the subarrays
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 7;
    int arr[7] = {3, -4, 5, 4, -1, 7, -8};

    for(int st=0;st<n;st++){
        for(int end=st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout << arr[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}