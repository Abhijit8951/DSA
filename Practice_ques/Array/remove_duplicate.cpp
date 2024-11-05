//Remove duplicates from a sorted array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 1, 2, 3, 3, 4};
    for(int i=1;i<vec.size();i++){
        if(vec[i] == vec[i-1]){
            vec.erase(vec.begin() + i);
        }
    }

    for(int num : vec){
        cout << num << endl;
    }

    return 0;
}