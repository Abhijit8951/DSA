//You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
// starting with word1. If a string is longer than the other, append the additional 
// letters onto the end of the merged string.
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r
#include <iostream>
#include <string>
using namespace std;

int main(){
    string word1 = "abc";
    string word2 = "pqr";

    int i = 0, j = 0;
    string str = "";
    while(i < word1.size() && j < word2.size()){
        str+=word1[i];
        str+=word2[j];
        i++;
        j++;
    }

    while(i < word1.size()){
        str+=word1[i];
        i++;
    }
    
        while(j < word2.size()){
        str+=word2[j];
        j++;
    }
    cout << str << endl;


    return 0;
}