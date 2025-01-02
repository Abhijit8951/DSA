#include <iostream>
using namespace std;

// Definition for singly-linked list node
class ListNode {
public:

    int x;
    ListNode* next;
    ListNode(int val){
        x = val;
        next = nullptr;
    }
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* forward = nullptr;

    while (curr != nullptr) {
        forward = curr->next;  // Save the next node
        curr->next = prev;     // Reverse the link
        prev = curr;           // Move prev one step ahead
        curr = forward;        // Move curr one step ahead
    }
    return prev; // New head of the reversed list
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->x << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to append a node to the linked list
ListNode* appendNode(ListNode* head, int val) {
    if (head == nullptr) {
        return new ListNode(val);
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

int main() {
    // Create a linked list
    ListNode* head = nullptr;
    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);
    head = appendNode(head, 5);

    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}
