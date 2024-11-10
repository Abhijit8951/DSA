//Linear search in a 2D-Array
#include <iostream>
using namespace std;

int main(){
    int matrix[4][3] = {{1, 2, 3},{4, 5, 6,},{7, 8, 9},{10, 11, 12}};
    int row=4;
    int column=3;
    int key=8;

    for(int  i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(matrix[i][j] == key){
                cout << "Key found in [" << i << "," << j << "]" << endl;
            }
        }
    }


    return 0;
}