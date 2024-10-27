//Priority Queues
#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int> q;
    q.push(5);
    q.push(4);
    q.push(10);
    q.push(2);
    q.push(7);

    while(!q.empty()){
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;


    return 0;
}