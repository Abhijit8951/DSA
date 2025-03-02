// Boundary traversal
//Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
// Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
// Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
// Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.
#include <iostream>
#include <vector>
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

void traverseLeft(Node* root, vector<int> &ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }
    ans.push_back(root->data);
    if (root->left) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(Node* root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(Node* root, vector<int> &ans) {
    if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);
    return ans;
}

void printBoundary(vector<int> boundary) {
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->right->left = new Node(10);
    root->right->right->right = new Node(11);
    
    vector<int> boundary = boundaryTraversal(root);
    printBoundary(boundary);
    
    return 0;
}