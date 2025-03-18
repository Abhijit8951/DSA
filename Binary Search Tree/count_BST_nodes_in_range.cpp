// Given a Binary Search Tree (BST) and a range l-h (inclusive), your task is to return the number of nodes in the BST whose value lie in the given range.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to count nodes within the given range [l, h]
int getCount(Node* root, int l, int h) {
    if (root == NULL) {
        return 0; // Base case: If the tree is empty, return 0
    }

    int count = 0;
    
    if (root->data >= l && root->data <= h) {
        count = 1;
    }

    // Recursively check left and right subtrees
    count += getCount(root->left, l, h);
    count += getCount(root->right, l, h);

    return count;
}

// Driver code
int main() {
    // Constructing the BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5, h = 45;
    cout << "Number of nodes in range [" << l << ", " << h << "]: " << getCount(root, l, h) << endl;

    return 0;
}