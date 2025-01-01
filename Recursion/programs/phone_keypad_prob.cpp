//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
//Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string digit, string output, int index, vector<string>& ans, string mapping[]){
    if (index >= digit.length()) {
        ans.push_back(output);
        return;
    }
    int number = digit[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans, mapping); // Recurse with next index
        output.pop_back();
    }
}

int main(){
    string digits = "23";
    vector<string> ans;

    if (digits.length() == 0) {
        cout << "Empty string...";
    }

    string output = "";
    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, ans, mapping);

    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}