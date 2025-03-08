// Kth ancestor of a binary tree
#include <iostream>
#include <climits>
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

Node* solve(Node* root, int &k, int node) {
    if (root == NULL)
        return NULL;
    
    if (root->data == node) 
        return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    if (leftAns != NULL && rightAns == NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if (leftAns == NULL && rightAns != NULL) {
        k--;
        if (k <= 0) {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
        return -1;
    else
        return ans->data;
}

// Helper function to insert nodes in the binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) return new Node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    int k = 2, node = 5;
    cout << "The " << k << "th ancestor of " << node << " is: " << kthAncestor(root, k, node) << endl;
    
    return 0;
}