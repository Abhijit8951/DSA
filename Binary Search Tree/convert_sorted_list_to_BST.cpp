// convert sorted linked list to a binary search tree
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return new TreeNode(head->val);
    
    ListNode* slow = head, *fast = head, *slow_prev = nullptr;
    
    while (fast != nullptr && fast->next != nullptr) {
        slow_prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* root = new TreeNode(slow->val);
    
    if (slow_prev) slow_prev->next = nullptr; 
    
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(slow->next);
    
    return root;
}

// Print the in-order traversal of the BST
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    // Sorted linked list: -10 -> -3 -> 0 -> 5 -> 9
    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    
    TreeNode* root = sortedListToBST(head);
    
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}