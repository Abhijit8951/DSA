//Swap nodes in pairs
//Given a linked list, swap every two adjacent nodes and return its head. 
//You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = nullptr;

        while (first != nullptr && sec != nullptr) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;

            if (prev != nullptr) {
                prev->next = sec;
            } else {
                head = sec;
            }

            prev = first;
            first = third;

            if (third != nullptr) {
                sec = third->next;
            } else {
                sec = nullptr;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array.
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    ListNode* swappedHead = solution.swapPairs(head);

    cout << "Swapped List: ";
    printList(swappedHead);

    return 0;
}
