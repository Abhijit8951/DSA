//Decimal to Binary
#include <iostream>
using namespace std;

int decToBinary(int n){
    int ans=0, pow=1;
    while(n>0){
        int rem=n%2;
        ans+=(rem*pow);
        n /= 2;
        pow *= 10;
    }
    return ans;
}

int main() {
    int n;
    cout << "enter a decimal number: ";
    cin >> n;
    cout << decToBinary(n) << endl;

    return 0;
}