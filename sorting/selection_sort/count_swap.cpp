//Count the number of swaps in selection sort
#include <iostream>
using namespace std;

int selectionSort(int arr[], int n){
    int count = 0;
    for(int i=0;i<n-1;i++){
        int smallestIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[smallestIdx]){   // Use if(arr[j] > arr[smallestIdx]) in case of descending order
                smallestIdx = j;
            }
        }
        if(i != smallestIdx){
            swap(arr[i], arr[smallestIdx]);
            count++;
        }
        
    }
    return count;
}

int main(){
    int n = 5;
    int arr[] = {4, 1, 5, 2, 3};
    int count = selectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "count: " << count << endl;

    return 0;
}