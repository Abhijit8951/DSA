#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int leftPoint=0, rightPoint=height.size()-1, maxWater=0;
    while(leftPoint < rightPoint){
        int w=rightPoint-leftPoint;
        int h=min(height[leftPoint], height[rightPoint]);
        int area=w*h;
        maxWater=max(maxWater, area);
        if(height[leftPoint] < height[rightPoint]){
            leftPoint++;
        } else{
            rightPoint--;
        }
    }

    cout << "Max water capacity is: " << maxWater << endl;

    return 0;
}