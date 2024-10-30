//Valid palindrome Strings
#include <iostream>
using namespace std;

bool isAlphaNum(char ch){
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
        return true;
    }
    return false;
}

int main(){

    // string s = "Ac3?e3c&a";
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int st=0, end = s.length()-1;
    bool isPalindrome = true;

    while(st < end){
        if(!isAlphaNum(s[st])) {
            st++; continue;
        }
        if(!isAlphaNum(s[end])) {
            end--; continue;
        }
        if(tolower(s[st]) != tolower(s[end])){
            isPalindrome = false;
            break;
        }
        st++;
        end--;
    }
    if(isPalindrome){
        cout << "palindrome...." << endl;
    } else{
        cout << "Not a palindrome...." << endl;
    }

    return 0;

}