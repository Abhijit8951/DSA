// Find minimum value in BST
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

int minValue(Node* root) {
    if (root == NULL) {
        return -1;
    }
    
    while (root->left != NULL) {
        root = root->left;
    }
    
    return root->data;
}

int main() {
    // Constructing the BST
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->left->left = new Node(1);
    
    cout << "Minimum value in BST: " << minValue(root) << endl;
    
    return 0;
}