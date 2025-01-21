//Flatten a multilevel doubly linked list
//You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, 
//and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also 
//containing these special nodes. These child lists may have one or more children of their own, and so on, to 
//produce a multilevel data structure as shown in the example below.
// Given the head of the first level of the list, flatten the list so that all the nodes appear in 
//a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child 
//list should appear after curr and before curr.next in the flattened list.
// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.
#include <iostream>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    // Constructor for convenience
    Node(int value) {
        val = value;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                // Flatten the child nodes
                Node* next = curr->next;
                curr->next = flatten(curr->child);

                curr->next->prev = curr;
                curr->child = nullptr;

                // Find the tail of the flattened child list
                while (curr->next != nullptr) {
                    curr = curr->next;
                }

                // Attach the tail to the next pointer
                if (next != nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            curr = curr->next;
        }
        return head;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Helper function to free the memory of the list
void freeList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    // Create a sample multilevel doubly linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    Solution solution;
    Node* flattenedHead = solution.flatten(head);

    // Print the flattened list
    cout << "Flattened List: ";
    printList(flattenedHead);

    // Free allocated memory
    freeList(flattenedHead);

    return 0;
}
