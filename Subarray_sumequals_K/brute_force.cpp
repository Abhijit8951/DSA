//Subarray sum equals k(Brute force)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {9, 4, 20, 3, 10, 5};
    int k = 33;
    int n = nums.size(), count = 0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum == k) count++;
        }
    }

    cout << "count: " << count << endl;

    return 0;
}