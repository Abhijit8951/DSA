//Palindrome partitioning
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(string part){
    string copy = part;
    reverse(copy.begin(), copy.end());

    return copy == part;
}

void getParts(string s, vector<string>& partitions, vector<vector<string>>& ans){

    if(s.size() == 0){
        ans.push_back(partitions);
        return;
    }

    for(int i=0; i<s.size(); i++){
        string part = s.substr(0, i+1);
        if(isPalindrome(part)){
            partitions.push_back(part);
            getParts(s.substr(i+1), partitions, ans);
            partitions.pop_back();
        }
    }
}

int main(){
    string s = "aab";
    vector<string> partitions;
    vector<vector<string>> ans;

    getParts(s, partitions, ans);

    for(const auto& row: ans){
        for(string val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;

}