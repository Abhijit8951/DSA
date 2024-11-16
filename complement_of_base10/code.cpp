//Complement of base 10 integer
#include <iostream>
using namespace std;

int  main(){
    int num;
    cout << "enter a number: ";
    cin >> num;

    //converting the num to binary
    int ans=0, pow = 1;
    while(num > 0){
        int rem = num%2;
        num /= 2;
        ans += (rem * pow);
        pow *= 10;
    }

    //changing the bits
    string str = to_string(ans);
    string complement = "";
    for (char bit : str) {
        if (bit == '0') {
            complement += '1'; // Change 0 to 1
        } else {
            complement += '0'; // Change 1 to 0
        }
    }
    int num2 = stoi(complement);

    //convering the binary to decimal
    int ans2=0, pow2=1;
    while(num2 > 0){
        int rem = num2%10;
        num2 /= 10;
        ans2 += (rem * pow2);
        pow2 *= 2;
    }
    cout << ans2 << endl;


    return 0;
}