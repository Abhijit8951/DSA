// Flatten BST to a sorted linked list
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

void inOrder(TreeNode* root, vector<int>& inOrderVal) {
    if (root == nullptr) return;
    
    inOrder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}

TreeNode* flatten(TreeNode* root) {
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);
    
    if (inOrderVal.empty()) return nullptr;
    
    TreeNode* newRoot = new TreeNode(inOrderVal[0]);
    TreeNode* curr = newRoot;
    
    for (size_t i = 1; i < inOrderVal.size(); i++) {
        TreeNode* temp = new TreeNode(inOrderVal[i]);
        curr->left = nullptr;
        curr->right = temp;
        curr = temp;
    }
    
    curr->left = nullptr;
    curr->right = nullptr;
    
    return newRoot;
}

int main() {
    // Creating a simple BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    
    TreeNode* flattenedRoot = flatten(root);
    
    TreeNode* curr = flattenedRoot;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
    
    return 0;
}