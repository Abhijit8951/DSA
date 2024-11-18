#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
    vector<int> nums = {1, 2, 2, 1, 1, 3};  //True as the occurance of all numbers are unique
    unordered_map<int, int> m1;
    for(auto i : nums){
        m1[i] += 1;
    }
    unordered_set<int> s1;
    for(auto i : m1){
        s1.insert(i.second);
    }

    if(s1.size() == m1.size()){
        cout << " True..." << endl;
    } else {
        cout << "false..." << endl;
    }



    return 0;
}