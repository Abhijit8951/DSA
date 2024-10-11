//Vector Functions
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //It returns the size of the element
    cout << "Size of vector: " << vec.size() << endl;
    //push_back functions inserts an element in the last of the vector
    vec.push_back(10);
    cout << vec[9] << endl;
    //pop_back function delets an element from last of the vector
    vec.pop_back();
    //front function prints the first element of the vector
    cout << vec.front() << endl;
    //back function prints the last element of the vector
    cout << vec.back() << endl;
    //at function is used for accessing a value at a particular index
    cout << vec.at(3) << endl;


    return 0;
}