//Find duplicate value
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {3, 1, 3, 4, 2};
    int slow = nums[0], fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);
    slow = nums[0];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    cout << slow << endl;


    return 0;
}