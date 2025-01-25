//Find N Unique Integers Sum up to Zero
// Given an integer n, return any array containing n unique integers such that they add up to 0.
#include <iostream>
#include <vector>
using namespace std;

vector<int> findAns(int n) {
    int sum = 0;
    if(n == 1) return {0};
    if (n == 2) return {-1,1};
    vector<int> res;
    for(int i=0; i<n-1; i++){
        res.push_back(i);
        sum += i;
    }
    res.push_back(-sum);
    return res;
}

int main() {
    int n = 5;
    vector<int> ans = findAns(n);
    for(int el : ans) {
        cout << el << " ";
    }
    cout << endl;



    return 0;
}