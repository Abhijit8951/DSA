//Insertion Sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev] > curr){   // Use while(prev >= 0 && arr[prev] < curr) in case of descending order
            arr[prev+1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }
}

int main(){
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};

    insertionSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}