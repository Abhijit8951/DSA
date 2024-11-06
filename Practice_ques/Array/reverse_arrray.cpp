//Reversing array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = 7, st = 0, end = size - 1;
    while(st < end){
        swap(arr[st], arr[end]);
        st++;
        end--;
    }

    for(int val : arr){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}