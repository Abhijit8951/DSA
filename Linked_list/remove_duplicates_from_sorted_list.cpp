//Remove duplicates from sorted list
//Input: head = [1,1,2]
// Output: [1,2]
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = head;
    
    while (head && head->next) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
    
    return res;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << std::endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 1, 2, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, size);
    cout << "Original List: ";
    printList(head);
    
    head = deleteDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    
    return 0;
}