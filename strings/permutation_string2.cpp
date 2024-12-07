//Permutation in string variation II(Returns true if permutation of s1 is present in s2 otherwise returns false)
#include <iostream>
#include <string>
using namespace std;

bool checkEqual(int a[26], int b[26]){
    for(int i=0; i<26; i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;
}

bool checkResult(string s1, string s2){
    int count1[26] = {0};
    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};

    while(i < windowSize && i < s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    if(checkEqual(count1, count2)){
        return true;
    }

    while(i<s2.length()){
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;
        char oldChar = s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;
        i++;

        if(checkEqual(count1, count2)){
            return true;
        }
    }

    return false;
}

int main(){
    string s1 = "ab", s2 = "eidbaooo";
    if(checkResult(s1, s2)){
        cout << "True" << endl;
    } else{
        cout << "False" << endl;
    }

    return 0;
}