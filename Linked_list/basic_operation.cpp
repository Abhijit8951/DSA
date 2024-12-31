#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    //Ading element in the front
    void push_front(int val){  //TC: O(1)
        Node* newNode = new Node(val);  //dynamic object
        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            newNode->next = head;
            head = newNode;
        }
    }

    //Adding element in the back
    void push_back(int val){  //TC: O(1)
        Node* newNode = new Node(val);  //dynamic object
        if(head == NULL){
            head = tail = newNode;
            return;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    //Deleting element from front
    void pop_front(){  //TC: O(1)
        if(head == NULL){
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        temp->next = NULL;

        delete temp;

    }

    //Deleting element from back
    void pop_back(){  //TC: O(n)
        if(tail == NULL){
            cout << "Empty Linked List" << endl;
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;

        delete tail;
        tail = temp;
    }

    //Inserting elements in the middle of linked list
    void insert(int val, int pos){  //TC: O(n)
        if(pos < 0){
            cout << "Invalid position\n";
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            if(temp == NULL){
                cout << "Inval;id pos\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key){  //TC: O(n)
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp->data == key){
                return idx;
            }

            temp = temp->next;
            idx++;
        }
        return -1;
    }

    //Printing the elements of linked list
    void printLL(){  //TC: O(n)
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    List ll;

    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_back(4);

    ll.pop_front();
    ll.pop_back();

    ll.insert(4, 2);

    ll.printLL();

    cout << "4 is present in the position: " << ll.search(4) << endl;

    return 0;
}