//Pairsum in case of unsorted vector
#include <iostream>
#include <map>
using namespace std;

int main(){
    vector<int> nums = {3, 2, 4}, ans;
    int target = 6;
    unordered_map<int, int> m;
    for(int i=0;i<nums.size();i++){
        int first = nums[i];
        int sec = target - first;

        if(m.find(sec) != m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;
        }
        m[first] = i;
    }
    for(int el : ans){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}