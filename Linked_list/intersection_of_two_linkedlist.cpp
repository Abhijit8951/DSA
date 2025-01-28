#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;

    ListNode *dummy1 = headA, *dummy2 = headB;

    while (dummy1 != dummy2) {
        dummy1 = dummy1 ? dummy1->next : headB;
        dummy2 = dummy2 ? dummy2->next : headA;
    }

    return dummy1;
}

int main() {
    ListNode *common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;


    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection node value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    delete common->next;
    delete common;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB->next->next->next;
    delete headB->next->next;
    delete headB->next;
    delete headB;

    return 0;
}
