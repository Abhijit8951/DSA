//flipped half diamond pattern
#include <iostream>
using namespace std;
// Function to print the triangle with n columns and 2*n-1
// rows
void printRotatedTriangle(int n){
    // First we print upper n rows out of the total 2*n-1
    // rows
    for (int i = 1; i <= n; i++) {

        // j iterates till n-i to print n-i number of spaces
        // in the (i)th row
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // k iterates till i to print i number of stars (*)
        // in the (i)th row
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        // line ends after printing i stars in (i)th row
        cout << endl;
    }

    // Now, we print other (n-1) rows of the triangle
    for (int i = 1; i <= n - 1; i++) {

        // j iterates till i to print i number of spaces in
        // the (i)th row
        for (int j = 1; j <= i; j++) {
            cout << " ";
        }

        // k iterates till n-i to print n-i number of stars
        // (*) in the (i)th row
        for (int k = 1; k <= n - i; k++) {
            cout << "*";
        }
        // line ends after printing n-i stars in (i)th row
        cout << endl;
    }
}

int main(){
    int n = 5;
    printRotatedTriangle(n);
    return 0;
}