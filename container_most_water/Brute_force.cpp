#include <iostream>
#include <vector>
using namespace std;

int main(){
    int maxWater = 0;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    for(int i=0;i<height.size();i++){
        for(int j=i+1;j<height.size();j++){
            int width=j-i;
            int h=min(height[i], height[j]);
            int area=width*h;

            maxWater=max(maxWater, area);
        }
    }

    cout << "Max water capacity is: " << maxWater << endl;

    return 0;
}