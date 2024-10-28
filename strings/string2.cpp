//Strings
#include <iostream>
using namespace std;

int main(){
    string str1 = "Abhijit";
    string str2 = "swain";

    string str3 = str1 + str2;   //concatenation

    cout << (str1 == str2) << endl;
    cout << (str1 > str2) << endl;
    cout << str1.length() << endl;
    cout << str3 << endl;

    for(int i=0;i<str3.length();i++){
        cout << str3[i] << " ";
    }
    cout << endl;
    
    reverse(str3.begin(), str3.end());
    cout << str3 << endl;

    return 0;
}