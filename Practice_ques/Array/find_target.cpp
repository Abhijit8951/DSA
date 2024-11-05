//Find a target in an array using binary serch
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {0, 2, 9, 5, 1, 7};
    int tar = 7;
    sort(vec.begin(), vec.end());
    int st = 0, end = vec.size() - 1;
    while(st <= end){
        int mid = st + (end-st) / 2;
        if(tar < vec[mid]){
            end = mid - 1;
        } else if(tar > vec[mid]){
            st = mid + 1;
        } else {
            cout << "The target found in " << mid << " index." << endl;
            return 0;
        }
    }

    return -1;
}