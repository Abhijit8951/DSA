//Find the factorial of a number using Recursion
#include <iostream>
using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }

    return n * fact(n-1);
}

int main(){
    cout << fact(5) << endl;


    return 0;
}