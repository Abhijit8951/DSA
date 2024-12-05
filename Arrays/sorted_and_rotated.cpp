//Check if an array is sorted and rotated
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums ={5, 6, 1, 2, 3, 4};
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n]) {
            count++;
        }
    }
    if(count <= 1){
        cout << "True..." << endl;
    } else {
        cout << "False..." << endl;
    }
    // return count <= 1

    return 0;
}