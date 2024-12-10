//Roatate array be 90deg
//Ex: Input: {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//    Output: {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> nums = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int size = nums.size();

    //transpose
    for(int i=0; i<size; i++){
        for(int j=0; j<=i; j++){
            swap(nums[i][j], nums[j][i]);
        }
    }

    //reversing the columns
    for(int i=0; i<size; i++){
        reverse(nums[i].begin(), nums[i].end());
    }

    //printing the elements
    for (const auto& row : nums) {
        for (int el : row) {
            cout << el << " ";
        }
        cout << endl;
    }


    return 0;
}