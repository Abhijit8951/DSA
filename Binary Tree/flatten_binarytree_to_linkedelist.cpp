// Flatten Binary tree to linked list
// Given the root of a binary tree, flatten the tree into a "Linked list":
// The "linked list" should use the same Node class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.
// Expected TC: O(N), SC: O(1)
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

void flatten(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            Node* pred = curr->left;

            while (pred->right) {
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// Helper function to print the flattened tree
void printFlattenedTree(Node* root) {
    while (root) {
        cout << root->data << " -> ";
        root = root->right;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    cout << "Flattening the tree..." << endl;
    flatten(root);

    printFlattenedTree(root);

    return 0;
}