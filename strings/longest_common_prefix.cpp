// Longest common prefix
#include <iostream>
#include <string>
using namespace std;

string prefix(vector<string> &strs){
    if (strs.empty()) return "";

    string pref = strs[0];
    int prefLen = pref.length();

    for (int i = 1; i < strs.size(); i++) {
        string s = strs[i];
        while (prefLen > s.length() || pref != s.substr(0, prefLen)) {
            prefLen--;
            if (prefLen == 0) {
                return "";
            }
            pref = pref.substr(0, prefLen);
        }
    }
    return pref;
}

int main(){
    vector<string> strs = {"flower","flow","flight"};
    string res = prefix(strs);

    cout << res << endl;
    


    return 0;
}