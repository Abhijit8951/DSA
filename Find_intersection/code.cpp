//Find intersection of two array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};  // common elements {2, 2, 3}
    int m = arr1.size(), n = arr2.size();
    vector<int> ans;

    int i = 0 , j = 0;
    while(i<m && j<n){
        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++; j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        } else{
            j++;
        }
    }

    for(int el : ans){
        cout << el << endl;
    }



    return 0;
}