// Lowest common ancestor in BST
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

// Function to find the Lowest Common Ancestor (LCA) in a BST
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != NULL) {
        if (root->val < p->val && root->val < q->val)
            root = root->right;
        else if (root->val > p->val && root->val > q->val)
            root = root->left;
        else {
            return root;
        }
    }
    return NULL;
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to search a node in BST
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->val == key) return root;
    
    if (key < root->val) return search(root->left, key);
    
    return search(root->right, key);
}

int main() {
    TreeNode* root = NULL;
    
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    TreeNode* p = search(root, 5);
    TreeNode* q = search(root, 15);

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}