//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again
// by continuously following the next pointer. Internally, pos is used to denote the index of the node that 
// tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
// Do not modify the linked list.
//Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} // Constructor
};

// Function to detect the node where the cycle begins in the linked list
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    // Detect if there is a cycle using two pointers
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    // If no cycle is found, return nullptr
    if (!fast || !fast->next) return nullptr;

    // Reset one pointer to the head and move both pointers at the same speed
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow; // The node where the cycle begins
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

    ListNode* cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    // Clean up memory (after breaking the cycle)
    fourth->next = nullptr; // Break the cycle
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
