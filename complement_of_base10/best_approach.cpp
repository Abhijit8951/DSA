//Complement of base 10 integer
#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "enter a number: ";
    cin >> num;

    if (num == 0){
        cout << 1 << endl;
        return 0;
    }

    int dupl = num;
    int mask = 0;
    while(dupl != 0){
        mask = (mask << 1) | 1;
        dupl = dupl >> 1;
    }
    int ans = (~num) & mask;
    cout << "Complement: " << ans << endl;

    return 0;
}