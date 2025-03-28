// Merge k sorted listd
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Comparator for the priority queue (Min-Heap)
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;  // Min-Heap: smallest element at top
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if (k == 0) return nullptr;

        // Insert first node of each list into the min heap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if (top->next != nullptr) {
                minHeap.push(top->next);
            }

            if (head == nullptr) {
                head = top;
                tail = top;
            } else {
                tail->next = top;
                tail = top;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating K sorted linked lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(7);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(5);
    list2->next->next = new ListNode(8);

    ListNode* list3 = new ListNode(3);
    list3->next = new ListNode(6);
    list3->next->next = new ListNode(9);

    vector<ListNode*> lists = {list1, list2, list3};

    Solution solution;
    ListNode* mergedHead = solution.mergeKLists(lists);

    cout << "Merged Sorted Linked List: ";
    printList(mergedHead);

    return 0;
}