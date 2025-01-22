//Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
//If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
// You may not alter the values in the list's nodes, only nodes themselves may be changed.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Helper function to reverse k nodes in a group
Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int count = 0;

    // Check if there are at least k nodes to reverse
    while (count < k) {
        if (temp == nullptr) {
            return head;
        }
        temp = temp->next;
        count++;
    }

    // Reverse the next k nodes
    Node* prevNode = reverseKGroup(temp, k);
    temp = head;
    count = 0;

    // Reverse current group of k nodes
    while (count < k) {
        Node* next = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = next;
        count++;
    }

    return prevNode;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    Node* head = createList(arr, sizeof(arr) / sizeof(arr[0]));

    std::cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    std::cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
