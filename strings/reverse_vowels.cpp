//Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
// Input: s = "IceCream"
// Output: "aceCreIm"
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "IceCream";
    string word = s;
    int st = 0;
    int end = s.length() - 1;
    string vowels = "aeiouAEIOU";

    while(st < end){
        while(st < end && vowels.find(word[st]) == -1){
            st++;
        }

        while(st < end && vowels.find(word[end]) == -1){
            end--;
        }

        swap(word[st], word[end]);
        st++;
        end--;
    }
    cout << word << endl;


    return 0;
}