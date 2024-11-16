//Number of distinct  triplets
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> nums = {-1,  0, 1, 2, -1, 4};
    int n = nums.size();
    set<vector<int>> unique;

    for(int i=0;i<n;i++){
        int tar = -nums[i];
        set<int> s;
        for(int j=i+1;j<n;j++){
            int third = tar - nums[j];

            if(s.find(third) != s.end()){
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                unique.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(unique.begin(), unique.end());
    cout << "The number of dictinct triplets are: " << unique.size() << endl;
    for (const auto& el : ans) {
        cout << el[0] << "," << el[1] << "," << el[2];
        cout << endl;
    }


    return 0;
}