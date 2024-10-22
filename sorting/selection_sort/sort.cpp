//Selection Sort
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int smallestIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[smallestIdx]){   // Use if(arr[j] > arr[smallestIdx]) in case of descending order
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

int main(){
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;
}