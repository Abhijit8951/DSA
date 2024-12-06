//Maximum occuring character in a string
#include <iostream>
using namespace std;

char getChar(string s){
    int arr[26] = {0};
    for(int i=0; i<s.size(); i++){
        char ch = s[i];

        int number = 0;
        if(ch >= 'a' || ch <= 'z'){
            number = ch - 'a';
        } else{
            number = ch - 'A';
        }

        arr[number]++;
    }

    int max = -1, ans = 0;
    for(int i=0; i<26; i++){
        if(max < arr[i]){
            max = arr[i];
            ans = i;
        }
    }
    char final = 'a' + ans;

    return final;
}

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << getChar(s) <<endl;


    return 0;
}