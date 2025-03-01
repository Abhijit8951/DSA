// Balanced Tree Check
// Given a binary tree, determine if it is height-balanced. 
// A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.
#include <iostream>
#include <cmath>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to calculate height and check if balanced
int checkHeight(Node* root, bool &isBalanced) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = checkHeight(root->left, isBalanced);
    int rightHeight = checkHeight(root->right, isBalanced);

    if (abs(leftHeight - rightHeight) > 1) {
        isBalanced = false;
    }

    return max(leftHeight, rightHeight) + 1;
}

// Function to check if the tree is balanced
bool isBalanced(Node* root) {
    bool isBalancedTree = true;
    checkHeight(root, isBalancedTree);
    return isBalancedTree;
}

// Driver code to test the function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //root->left->left->left = new Node(6);  // Unbalancing the tree

    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}