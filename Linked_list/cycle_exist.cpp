//Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again 
// by continuously following the next pointer. Internally, pos is used to denote the index of the 
// node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
};

// Function to detect a cycle in the linked list
bool hasCycle(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            return true;
        }
    }

    return false;
}

// Function to clean up the linked list memory(Optional)
void cleanUp(ListNode* head) {
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating a linked list with a cycle
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // Creating a cycle

    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;

        // Breaking the cycle manually for cleanup
        fourth->next = nullptr; // Remove the cycle for proper cleanup
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Clean up the linked list
    cleanUp(head);

    return 0;
}
