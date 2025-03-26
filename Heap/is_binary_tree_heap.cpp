// Is Binary Tree Heap
// You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int count) {
    if (root == NULL) {
        return true;
    }
    if (index >= count) {
        return false;
    }
    return isCBT(root->left, 2 * index + 1, count) && isCBT(root->right, 2 * index + 2, count);
}

bool isMaxOrder(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->right == NULL) {
        return (root->left->data < root->data);
    }
    return isMaxOrder(root->left) && isMaxOrder(root->right) &&
           (root->left->data < root->data && root->right->data < root->data);
}

bool isHeap(Node* root) {
    int index = 0;
    int totalCount = countNodes(root);
    return isCBT(root, index, totalCount) && isMaxOrder(root);
}

int main() {
    Node* root = new Node{10, new Node{9, new Node{7, NULL, NULL}, new Node{6, NULL, NULL}},
                              new Node{8, NULL, NULL}};
    
    if (isHeap(root)) {
        cout << "The given binary tree is a Heap" << endl;
    } else {
        cout << "The given binary tree is not a Heap" << endl;
    }
    
    return 0;
}