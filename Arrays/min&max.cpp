//Finding largest and smallest element in an array
#include <iostream>
using namespace std;

int main(){
    int nums[] = {25, 78, -8, 7, 45, 78};
    int size = 6;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i=0;i<size;i++){
        if(nums[i] < smallest){
            smallest = nums[i];
        }

        if(nums[i] > largest){
            largest = nums[i];
        }
    }
    cout << "Largest number is: " << largest << endl;
    cout << "Smallest number is: " << smallest << endl;

    return 0;
}