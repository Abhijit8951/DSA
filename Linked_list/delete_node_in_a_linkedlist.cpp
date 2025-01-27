//Delete node in a linked list
//You will not be given access to the first node of head.
//Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void deleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        std::cerr << "Node to delete cannot be null or the last node!" << std::endl;
        return;
    }
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;  // Free the memory of the deleted node
}

int main() {
    // Creating a simple linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Deleting the node with value 5
    ListNode* nodeToDelete = head->next;  // Node with value 5
    deleteNode(nodeToDelete);

    // Printing the updated linked list: 4 -> 1 -> 9
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
