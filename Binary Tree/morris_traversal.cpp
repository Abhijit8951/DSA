// Given a Binary Tree, the task is to print its Inorder Traversal, without using recursion or stack
// Inorder traversal (Left->Root->Right)
// Using Morris Traversal, we can traverse the tree without using stack and recursion. The idea of Morris traversal is based on Threaded Binary Tree. In this traversal, we first create links to Inorder successor and print the data using these links, 
// and finally revert the changes to restore original tree. Although the tree is modified through the traversal, it is reverted back to its original shape after the completion. Unlike Stack based traversal, no extra space is required for this traversal.
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

using namespace std;
vector<int> inOrder(Node* root) {
    vector<int> res;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
  
    for (int data : res) {
        cout << data << " ";
    }
    cout << endl;
    
    return 0;
}