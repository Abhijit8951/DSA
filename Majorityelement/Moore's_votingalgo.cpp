//Moore's voting Algorithm
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 1, 1, 2};
    int n = nums.size();
    int freq=0, ans=0;

    for(int i=0;i<n;i++){
        if(freq == 0) {
            ans = nums[i];
        }

        if(ans == nums[i]) {
            freq++;
        } else {
            freq--;
        }
    }
    cout << "Majority element: " << ans << endl;


    return 0;
}