//Pairs
#include <iostream>
#include <vector>
using namespace std;

int main(){
    pair<char, int> p = {'A', 1};
    cout << p.first << endl;
    cout << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    cout << p2.first << endl;
    cout << p2.second.first << endl;
    cout << p2.second.second << endl;

    vector<pair<int, int>> vec = {{11, 25}, {12, 31}, {13, 43}};
    vec. push_back ({4, 5});
    vec. emplace_back (7, 8);
    for(pair<int, int> p : vec){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}