//power of 2
#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int ans = 1;
    for(int i=0;i<=30;i++){
        if(ans == num){
            cout << "True" << endl;
            return 0;
        } 

        if(ans < INT_MAX/2) ans = ans * 2;
    }
    cout << "False" << endl;


    return 0;
}