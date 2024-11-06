//Remove duplicates from a sorted array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 1, 2, 2, 3, 3, 4};
    int findNum = 0;
    for(int val : vec){
        findNum ^=  val;
    }
    cout << findNum << endl;

    return 0;
}