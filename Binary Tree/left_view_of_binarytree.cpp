// Left view of binary tree
// You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
// If the tree is empty, return an empty list.
#include <iostream>
#include <vector>
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

// Function to compute the left view of the binary tree
void solve(Node* root, vector<int> &ans, int level) {
    if (root == NULL) {
        return;
    }
    
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// Function to build a sample binary tree
Node* buildTree() {
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
    Node* root = buildTree();
    vector<int> result = leftView(root);
    
    cout << "Left View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}