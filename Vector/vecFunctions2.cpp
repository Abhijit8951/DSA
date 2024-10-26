//Vector Functions (Part2)
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};

    //erase function deletes a element from a prticular index
    vec.erase(vec.begin());
    vec.erase(vec.begin() + 1, vec.begin() + 3);

    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;

    //insert function inserts element in a particular index
    vec.insert(vec.begin() +2, 100);

    for(int el : vec){
        cout << el << " ";
    }

    //clear function clears all the elements of a vector
    vec.clear();
    for(int el : vec){
        cout << el << " ";
    }
    cout << endl;
}