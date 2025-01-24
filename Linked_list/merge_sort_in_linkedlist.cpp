//Merge sort in linked list
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to find the middle of the linked list
Node* getMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* result = nullptr;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Merge sort function
Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    // Split the linked list into two halves
    Node* middle = getMiddle(head);
    Node* nextToMiddle = middle->next;
    middle->next = nullptr;

    // Recursively sort the two halfs
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMiddle);

    // Merge the two sorted halves
    return merge(left, right);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 4);
    insertAtEnd(head, 2);
    insertAtEnd(head, 8);
    insertAtEnd(head, 5);
    insertAtEnd(head, 1);

    cout << "Original list: ";
    printList(head);

    // Sorting the linked list
    head = mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}