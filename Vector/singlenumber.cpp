//Find the unique element in a vector
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {4, 1, 2, 1, 2};
    int ans = 0;
    for(int val : vec){
        ans = ans^val;
    }

    cout << "Th eunique element is: " << ans << endl;

    return 0;
}