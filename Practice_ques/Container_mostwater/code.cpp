//Container with most water
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int st = 0, end = vec.size() - 1, maxwater = INT_MIN;
    while(st < end){
        int h = min(vec[st], vec[end]);
        int w = end - st;
        int area = h * w;
        maxwater = max(maxwater, area);
        if(vec[st] < vec[end]){
            st++;
        } else {
            end--;
        }
    }
    
    cout << "The most water  is " << maxwater << endl;

    return 0;
}