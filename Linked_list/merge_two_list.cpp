//Merge two linked lists
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL)
        return list2;

    if (list2 == NULL)
        return list1;

    ListNode* ptr = list1;
    if (list1->val > list2->val) {
        ptr = list2;
        list2 = list2->next;
    } else {
        list1 = list1->next;
    }
    ListNode* curr = ptr;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (!list1)
        curr->next = list2;
    else
        curr->next = list1;

    return ptr;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage (using array for simplicity)
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    ListNode* list1 = createList(arr1, 3);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
