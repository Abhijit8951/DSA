//Lists
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
    list<int> l = {4, 7, 9};
    l.push_back(3);
    l.push_back(5);
    l.push_front(1);
    l.push_front(2);
    l.emplace_back(6);

    l.pop_back();
    l.pop_front();

    for(int el : l){
        cout << el << " ";
    }
    cout << endl;


    return 0;
}