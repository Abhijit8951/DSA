//Dynamic Array
#include <iostream>
using namespace std;

void fill(int **p, int rowSize, int columnSize){
    for(int row=0; row<rowSize; row++){
        for(int column=0; column<columnSize; column++){
            cout << "Enter the value for board " << row << "," <<  column << " : ";
            cin >> p[row][column];
        }
        cout << endl;
    }
}

void print(int **p, int rowSize, int columnSize){
    for(int row=0; row<rowSize; row++){
        for(int column=0; column<columnSize; column++){
            cout << p[row][column] << " ";
        }
        cout << endl;
    }
}

int main(){
    int **board;
    int rows, columns;

    cout << "Enter the number of rows: "
        << "And columns: ";
    cin >> rows >> columns;
    cout << endl;

    board = new int* [rows];

    for(int row=0; row <rows; row++){
        board[row] = new int[columns];
    }

    fill(board, rows, columns);

    print(board, rows, columns);


    return 0;
}