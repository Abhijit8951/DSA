//Find all valid combinations of k numbers that sum up to n 
//such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
#include <iostream>
#include <vector>
using namespace std;

void help(vector<vector<int>> &res,vector<int> &temp,vector<int>&keys,int tar,int k,int sm,int i){
    if(i==9){
        if(tar==sm && k==temp.size()){
            res.push_back(temp);
        }
        return ;
    }
    help(res,temp,keys,tar,k,sm,i+1);
    if(sm<=tar){
        temp.push_back(keys[i]);
        help(res,temp,keys,tar,k,sm+keys[i],i+1);
        temp.pop_back();
    }
}

int main(){
    int k = 3, n = 9;
    vector<vector<int>>  res;
    vector<int> temp;
    vector<int> keys={1,2,3,4,5,6,7,8,9};
    help(res,temp,keys,n,k,0,0);

    for(auto &row: res){
        for(int el : row){
            cout << el << " ";
        }
        cout << endl;
    }


    return 0;
}