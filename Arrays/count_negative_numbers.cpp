//Count negative numbers in a sorted array
#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<vector<int>> grid = {{4, 3, 2, 1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
    int m = grid.size();
    int n = grid[0].size();

    int count = 0;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] < 0) {
                count++;
            }
        }
    }

    cout << "The total number of negative numbers are: "<< count << endl;



    return 0;
}