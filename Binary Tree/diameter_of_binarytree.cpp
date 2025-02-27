// Diameter of a Binary Tree
//Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes 
//in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree
#include <iostream>
#include <utility>
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

pair<int, int> diameterFast(Node* root) {
    if (root == NULL) {
        return make_pair(0, 0);
    }
    
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}

int diameter(Node* root) {
    return diameterFast(root).first - 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << "Diameter of the tree: " << diameter(root) << endl;
    
    return 0;
}