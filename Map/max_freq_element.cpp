// Maximum frequency element
// Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.
// If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.
// For example,
// For 'arr' = [ 1, 2, 3, 1, 2]. you need to return 1.
#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

int getAns(vector<int>& arr) {
    unordered_map<int, int> m;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0; i<arr.size(); i++) {
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++) {
        if(maxFreq == m[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;

}

int main() {
    vector<int> arr = { 1, 2, 3, 1, 2};

    int ans = getAns(arr);
    cout << "The max occuring element is: " << ans << endl;


    return 0;
}