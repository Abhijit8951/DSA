//Maximum column sum in a 2D-Array
#include <iostream>
using namespace std;

int maxColumnSum(int matrix[][3], int column, int row){
    int maxcolsum = INT_MIN;
    for(int i=0;i<column;i++){
        int currsum=0;
        for(int j=0;j<row;j++){
            currsum=currsum+matrix[j][i];
        }
        maxcolsum=max(maxcolsum, currsum);
    }
    return maxcolsum;
}

int main(){
    int matrix[4][3] = {{1, 2, 3},{4, 5, 6,},{7, 8, 9},{10, 11, 12}};
    int row=4;
    int column=3;

    cout << maxColumnSum(matrix, column, row) << endl;

    return 0;
}