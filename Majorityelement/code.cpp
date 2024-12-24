//Given an integer array of size n, find all elements that appear more than 'n/3' times.
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    vector<int> nums = {3, 1, 3};
    int n = nums.size();
    unordered_set<int> s;

    for(int val : nums){
        int freq = 0;
        for(int el : nums){
            if(el == val){
                freq++;
            }
        }
        if(freq > n/3){
            if(s.find(val) == s.end()){  //This line is optional as unordered set doesn't accept duplicate values
                s.insert(val);
            }
        }
    }
    vector<int>(s.begin(), s.end());  //convert set to a vector

    for(int val : s){
        cout << val << " ";
    }
    cout << endl;


    return 0;
}