//Remove a given element from an array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {3, 2, 2, 3};
    int n = vec.size();
    int tar = 3, i = 0;
    for(int j=0;j<n;j++){
        if(vec[j] != tar){
            vec[i] = vec[j];
            i++;
        }
    }
    vec.resize(i);
    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}