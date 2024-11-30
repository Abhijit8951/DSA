//Insertion Sort (nother approach)
#include <iostream>
using namespace std;

void insertionSort(int  arr[], int n){
    for(int i=1; i<n; i++){
        int  temp = arr[i];
        int  j = i-1;
        for(; j>=0; j--){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;
    insertionSort(arr, n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;


    return 0;
}