//Power Exponentiation
#include <iostream>
using namespace std;

int main(){
    double num;
    int power;
    cout << "Enter a number: ";
    cin >> num;
    cout  << "Enter it's power: ";
    cin >> power;
    if(power == 0){
        cout << "The result is: " << 1 << endl;
        return 0;
    }
    if(num == 1){
        cout << "The result is: " << 1 << endl;
        return 0;
    }

    double ans=1.0;
    long long abspower=power;

    if(power<0){
        num=1/num;
        abspower=-abspower;
    }
    
    while(abspower>0){
        if(abspower%2==1){
            ans*=num;
        }
        num *= num;
        abspower /= 2;
    }

    cout << "The result is: " << ans << endl;


    return 0;
}