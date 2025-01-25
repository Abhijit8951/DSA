//Sort aray by parity
//Input: [3, 1, 2, 4]
//Output: [2, 4, 3, 1]
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 2, 4};
    int even = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]%2 == 0) {
            swap(nums[i], nums[even]);
            even++;
        }
    }

    for(int el : nums) {
        cout << el << " ";
    }
    cout << endl;


    return 0;
}