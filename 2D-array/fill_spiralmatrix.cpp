//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n^2 in spiral order. (Leetcode - 59)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 3;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int srow = 0, scol = 0, erow = n-1, ecol = n-1;
    int number = 1;

    while(srow <= erow && scol <= ecol){
        //top filling
        for(int j=scol; j<=ecol;j++){
            nums[srow][j] = number;
            number++;
        }

        //right filling
        for(int i=srow+1;i<=erow;i++){
            nums[i][ecol] = number;
            number++;
        }

        //bottom fillling
        for(int j = ecol-1;j>=scol;j--){
            if(srow == erow){
                break;
            }

            nums[erow][j] = number;
            number++;
        }

        //left filling
        for(int i=erow-1;i>=srow+1;i--){
            if(scol == ecol){
                break;
            }

            nums[i][scol] = number;
            number++;
        }
        srow++; erow--;scol++;ecol--;
    }

    // Print the matrix
    for (const auto& row : nums) {
        for (int el : row) {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}