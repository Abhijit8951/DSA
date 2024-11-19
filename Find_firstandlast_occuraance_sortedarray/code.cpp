// Find first ans last occurance of a element in a sorted array
#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> nums, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(nums[mid] == key){
            ans = mid;
            e = mid - 1;
        } else if(key > nums[mid]){
            s = mid + 1;
        } else if(key < nums[mid]){
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int lastOcc(vector<int> nums, int n, int key){
    int s = 0, e = n - 1;
    int mid = s + (e - s)/2;
    int ans = -1;

    while(s <= e){
        if(nums[mid] == key){
            ans = mid;
            s = mid + 1;
        } else if(key > nums[mid]){
            s = mid + 1;
        } else if(key < nums[mid]){
            e = mid - 1;
        }
        mid = s + (e - s)/2;
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 2, 3, 3, 5};
    pair<int, int> p;
    int n = nums.size();
    int key = 3;

    p.first = firstOcc(nums, n, key);
    p.second = lastOcc(nums, n, key);


    cout << "First occurrence of 3 is: " << p.first << endl;
    cout << "Last occurrence of 3 is: " << p.second << endl;


    return 0;
}