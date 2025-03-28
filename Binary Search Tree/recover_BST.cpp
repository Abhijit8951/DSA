#include <iostream>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Inorder traversal to detect swapped nodes
void inorder(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
    if (!root) return;

    inorder(root->left, first, second, prev);

    // Detect swapped nodes
    if (prev && prev->val > root->val) {
        if (!first) first = prev;
        second = root;
    }

    prev = root;  // Move prev to current node

    inorder(root->right, first, second, prev);
}

// Function to recover the BST
void recoverTree(TreeNode* root) {
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;
    inorder(root, first, second, prev);
    swap(first->val, second->val);
}

// Helper function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // BST with swapped nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Before fixing: ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "After fixing: ";
    printInorder(root);
    cout << endl;

    return 0;
}