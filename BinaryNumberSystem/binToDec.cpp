//Binary to Decimal
#include <iostream>
using namespace std;

int binToDecimal(int n){
    int ans=0,pow=1;
    while(n>0){
        int rem = n%10;
        ans += (rem*pow);
        n /= 10;
        pow *= 2;
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << binToDecimal(n) << endl;

    return 0;
}