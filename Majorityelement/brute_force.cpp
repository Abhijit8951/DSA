//Find the majority element using brute-force approach
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {2, 1, 2, 1, 1};
    int n = vec.size();

    for(int val : vec){
        int freq = 0;
        for(int el : vec){
            if(el == val){
                freq++;
            }
        }
        if(freq>n/2){
            cout << val << endl;
            return 0;
        }
    }
    return -1;
}