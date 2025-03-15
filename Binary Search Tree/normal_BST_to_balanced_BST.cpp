// Normal BST to balanced BST
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

void inOrder(TreeNode* root, vector<int>& inOrderval) {
    if (root == nullptr) return;
    
    inOrder(root->left, inOrderval);
    inOrderval.push_back(root->data);
    inOrder(root->right, inOrderval);
}

TreeNode* inOrderToBST(int s, int e, vector<int>& inOrderval) {
    if (s > e) {
        return nullptr;
    }
    
    int mid = (s + e) / 2;
    
    TreeNode* root = new TreeNode(inOrderval[mid]);
    root->left = inOrderToBST(s, mid - 1, inOrderval);
    root->right = inOrderToBST(mid + 1, e, inOrderval);
    
    return root;
}

TreeNode* balancedBst(TreeNode* root) {
    vector<int> inOrderval;
    inOrder(root, inOrderval);
    
    return inOrderToBST(0, inOrderval.size() - 1, inOrderval);
}

void printInOrder(TreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    // Creating a sample unbalanced BST
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(20);
    
    cout << "Original InOrder Traversal: ";
    printInOrder(root);
    cout << endl;
    
    TreeNode* balancedRoot = balancedBst(root);
    
    cout << "Balanced BST InOrder Traversal: ";
    printInOrder(balancedRoot);
    cout << endl;
    
    return 0;
}