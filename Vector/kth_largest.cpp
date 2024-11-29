//Find kth largest element in a vector
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int n = nums.size();
    int k = 2;

    sort(nums.begin(), nums.end());

    cout << nums[n-k] << endl;


    return 0;
}