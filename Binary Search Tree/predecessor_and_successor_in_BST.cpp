#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find predecessor and successor
void findPredecessorSuccessor(TreeNode* root, int key, int &pred, int &succ) {
    TreeNode* temp = root;
    pred = -1, succ = -1;

    while (temp != NULL && temp->data != key) {
        if (temp->data > key) {
            succ = temp->data;  // Possible successor
            temp = temp->left;
        } else {
            pred = temp->data;  // Possible predecessor
            temp = temp->right;
        }
    }

    if (temp == NULL) return;

    TreeNode* leftTree = temp->left;
    while (leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode* rightTree = temp->right;
    while (rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

int main() {
    TreeNode* root = NULL;
    
    // Creating the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    int pred, succ;
    
    findPredecessorSuccessor(root, key, pred, succ);

    cout << "Predecessor: " << pred << endl;
    cout << "Successor: " << succ << endl;

    return 0;
}