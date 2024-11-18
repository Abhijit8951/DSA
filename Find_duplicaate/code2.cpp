//Find duplicate value (Another approach)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 1, 3, 4, 2};
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans ^= nums[i];
    }

    for(int i=1;i<nums.size();i++){
        ans ^= i;
    }
    cout << ans << endl;


    return 0;
}