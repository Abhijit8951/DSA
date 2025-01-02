//Find in mountain array
#include <iostream>
#include <vector>
using namespace std;

//Finding the peak element
int findPeakIndex(int low, int high, vector<int> mountain){
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (mountain[mid] < mountain[mid+1]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

//searching for elements in both left & right side
int binarySearch(int st, int end, int target, vector<int> mountain){
    while(st <= end){
        int mid = st + (end-st) / 2;

        if(mountain[mid] == target){
            return mid;
        } else if(target > mountain[mid]){
            st = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> mountain = {1, 2, 3, 4, 5, 3, 1};
    int target = 3;
    int n = mountain.size();

    int peakIndex = findPeakIndex(1, n - 2, mountain);

    int incIndex = binarySearch(0, peakIndex, target, mountain);
    int decIndex = binarySearch(peakIndex + 1, n - 1, target, mountain);

    if(incIndex == -1){
        cout << "Index: " << decIndex << endl;
    } else{
        cout << "Index: " << incIndex << endl;
    }



    return 0;
}