//Sets
#include <iostream>
#include <set>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(4);
    s.insert(5);
    s.insert(2);
    s.insert(3);
    //Don't accept duplicate values
    s.insert(2);
    s.insert(3);

    for(int val : s){
        cout << val << " ";
    }
    cout << endl;

    cout << "Lower bound of 3: " << *(s.lower_bound(3)) << endl;
    cout << "Upper bound of 3: " << *(s.upper_bound(3)) << endl;


    return 0;
}