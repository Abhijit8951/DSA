//Find missing and repeated values 
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}}; //The repeated value is 9 and the missing value is 5
    vector<int> ans;
    unordered_set<int> s;
    int n = grid.size(), a, b, expsum = 0, actualsum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            actualsum += grid[i][j];
            if(s.find(grid[i][j]) != s.end()){
                a=grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
        }
    }
    expsum = (n*n) * (n*n + 1) / 2;
    b = expsum + a - actualsum;
    ans.push_back(b);
    for(int el : ans){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}