// Lowest common ancestor in Binary Tree
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

// Function to return the lowest common ancestor in a Binary Tree.
Node* lca(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);
    
    if (leftAns != NULL && rightAns != NULL) {
        return root;
    } else if (leftAns != NULL) {
        return leftAns;
    } else {
        return rightAns;
    }
}

// Function to insert nodes manually (for testing purposes)
Node* insert() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}

int main() {
    Node* root = insert();
    
    int n1 = 4, n2 = 5;
    Node* ancestor = lca(root, n1, n2);
    
    if (ancestor) {
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }
    
    return 0;
}