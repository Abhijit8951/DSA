//String compression
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> chars = {"a","a","b","b","c","c","c"};
    int n = chars.size(), idx = 0; 
    for(int i=0;i<n;i++){
        string ch = chars[i];
        int count = 0;
        while(i < n && chars[i] == ch){
            count++; i++;
        }
        if(count == 1){
            chars[idx++] = ch;
        } else{
            chars[idx++] = ch;
            string str = to_string(count);
            for(char dig : str){
                chars[idx++] = dig;
            }
        }
        i--;
    }
    chars.resize(idx);
    int size = chars.size();
    for (string ch : chars) {
        cout << ch;
    }
    cout << endl;
    cout << "Size of the new array is: " << size << endl;


    return 0;
}