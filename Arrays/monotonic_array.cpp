//Monotonic array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 2, 3};
    bool isInc = false, isDec = false;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                isInc = true;
            } else if(nums[i-1] > nums[i]){
                isDec = true;
            }

            if(isInc && isDec){
                cout << "Not a monotonic arrray...";
            }
        }
        cout << "Monotonic array...";

    return 0;
}