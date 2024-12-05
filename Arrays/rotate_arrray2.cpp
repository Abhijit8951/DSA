//Rotate array approach II
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int n = nums.size();
    vector<int> temp(n);
    for(int i=0; i<n; i++){
        temp[(i+k)%n] = nums[i];
    }
    nums=temp;

    for(int el : nums){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}