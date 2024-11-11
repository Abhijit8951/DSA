//Pyramid Pattern
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for(int i=0;i<n;i++){

        //for spaces
        for(int j=0;j<n-1-i;j++){
            cout << " ";
        }

        //for 1st nums
        for(int j=1;j<=i+1;j++){
            cout << j;
        }

        //for 2nd nums
        for(int j=1;j<=i;j++){
            cout << j;
        }
        cout << endl;
    }
    

    return 0;
}