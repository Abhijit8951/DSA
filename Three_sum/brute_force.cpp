//Three sum(Brute Force)
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, 4};
    int n = nums.size();
    vector<vector<int>> ans;
    set<vector<int>> s;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());

                    if(s.find(triplet) == s.end()){
                        s.insert(triplet);
                        ans.push_back(triplet);
                    }
                }
            }
        }
    }

    for (const auto& triplet : ans) {
        cout << triplet[0] << "," << triplet[1] << "," << triplet[2];
        cout << endl;
    }
    

    return 0;
}