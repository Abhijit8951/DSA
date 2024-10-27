//Maps
#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> m;

    m["laptop"] = 175;
    m["phone"] = 250;
    m["headphone"] = 122;

    m.insert({"keyboard", 100});
    
    // Check if the key exists using count
    cout << "Keyboard count: " << m.count("keyboard") << endl;

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }
    cout << "After erase:  " << endl;

    m.erase("phone");

    for(auto p : m){
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}