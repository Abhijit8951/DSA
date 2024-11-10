//Sarch in a 2D matrix varriation II
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},{2, 5, 8, 12, 19},{3, 6, 9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};
    int target = 5;
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;

    while(r < m && c >= 0){
        if(target == matrix[r][c]){
            cout << "Target found in: " << r << "," << c << endl;
            break;
        }
        if(target < matrix[r][c]){
            c--;
        }
        if(target > matrix[r][c]){
            r++;
        }
        
    }

    return 0;
}