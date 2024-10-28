//Strings
#include <iostream>
using namespace std;

int main(){
    char str[14];

    cout << "Enter char array: ";
    cin.getline(str, 100);

    // cout << " Output: " << str << endl;
    for(char ch : str){
        cout << ch << " ";
    }
    cout << endl;
    


    return 0;
}