//Max number of K-sum pairs
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 1, 3, 4, 3};
    int k = 6;
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1, ans = 0;

    while(i < j){
        int res = nums[i] + nums[j];

        if(res == k){
            ans++;
            i++; j--;
        }

        if(res < k){
            i++;
        }

        if(res > k){
            j--;
        }
    }
    cout << "Number of pairs: " << ans << endl;


    return 0;
}