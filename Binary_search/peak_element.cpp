//Peak index in mountain array
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {0, 3, 8, 9, 5, 2};
    int n = nums.size();
    int st=0, end=n-1;

    while (st <= end) {
            int mid = st + (end - st) / 2;

            // Check if mid is the peak element
            bool left_smaller = (mid == 0) || (nums[mid] > nums[mid - 1]);
            bool right_smaller = (mid == n - 1) || (nums[mid] > nums[mid + 1]);

            if (left_smaller && right_smaller) {
                cout <<  nums[mid] << endl;
                return 0;
            } 
            else if (left_smaller && !right_smaller) {
                st = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return -1;
}