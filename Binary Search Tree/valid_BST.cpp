// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBST(TreeNode* root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->val <= min || root->val >= max) {
        return false;
    }

    return isBST(root->left, min, root->val) && 
           isBST(root->right, root->val, max);
}

bool isValidBST(TreeNode* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) {
        cout << "The tree is a valid BST" << endl;
    } else {
        cout << "The tree is not a valid BST" << endl;
    }
    
    return 0;
}