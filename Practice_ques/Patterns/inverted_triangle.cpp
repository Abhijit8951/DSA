//Inverted Triangle Pattern
#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout << " ";
        }

        for(int j=n-i;j>=1;j--){
            cout << i+1;
        }
        cout << endl;
    }

    return 0;

}