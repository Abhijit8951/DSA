// Invert binary tree
// Given the root of a binary tree, invert the tree, and return its root.
// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
#include <iostream>
using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

// Function to invert a binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

// Function to print Inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();
    
    cout << "Original Tree (Inorder): ";
    inorderTraversal(root);
    cout << endl;
    
    root = invertTree(root);
    
    cout << "Inverted Tree (Inorder): ";
    inorderTraversal(root);
    cout << endl;
    
    return 0;
}