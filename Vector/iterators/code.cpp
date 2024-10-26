//Vector Iterators
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {1, 2, 3, 4};

    cout << "vector begin: " << *(vec.begin()) << endl;
    cout << "vector end: " << *(vec.end()) << endl;

    //Forward loop
    vector<int>::iterator itr;
    for(itr=vec.begin();itr!=vec.end();itr++){
        cout << *(itr) << endl;
    }

    //Alternate way
    for(auto itr=vec.begin();itr!=vec.end();itr++){
        cout << *(itr) << endl;
    }

    //Backward loop
    vector<int>::reverse_iterator itr2;
    for(itr2=vec.rbegin();itr2!=vec.rend();itr2++){
        cout << *(itr2) << endl;
    }

    return 0;
}