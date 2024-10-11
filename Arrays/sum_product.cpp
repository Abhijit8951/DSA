//function to calculate sum & product of all numbers in an array
#include <iostream>
using namespace std;

void calculate(int arr[], int size){
    int sum=0,product=1;
    for(int i=0;i<size;i++){
        sum+=arr[i];
        product*=arr[i];
    }

    cout << "sum: " << sum << endl;
    cout << "Product: " << product << endl;
}

int main(){
    int arr[] = {1, 5, 3, 6, 9, 7};
    int size = 6;
    calculate(arr, size);

    return 0;
}