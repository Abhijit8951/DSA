//Sort an array with 0s, 1s, 2s using Dutch National Flag  Algorithm
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {2, 0, 1, 1, 0, 1, 2, 0, 0};
    int n = arr.size();
    int mid=0, low=0, high=n-1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        } else if(arr[mid] == 1){
            mid++;
        } else{
            swap(arr[high], arr[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}