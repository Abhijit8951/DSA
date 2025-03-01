// Identical Trees
// Given two binary trees with their root nodes r1 and r2, return true if both of them are identical, otherwise, false.
#include <iostream>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if two trees are identical
bool isIdentical(Node* r1, Node* r2) {
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }
    
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }
    
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int main() {
    // Creating two identical trees
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    
    if (isIdentical(root1, root2)) {
        cout << "The trees are identical." << endl;
    } else {
        cout << "The trees are not identical." << endl;
    }
    
    return 0;
}
