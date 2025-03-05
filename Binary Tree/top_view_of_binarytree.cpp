// Top view of binary tree
//You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
// Note: 
// Return the nodes from the leftmost node to the rightmost node.
// If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only. 
// Examples:
// Input: root[] = [1, 2, 3] 
// Output: [2, 1, 3]
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to return the top view of a binary tree
vector<int> topView(Node* root) {
    vector<int> ans;
    if (!root) return ans;
    
    map<int, int> hdMap;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        
        Node* node = it.first;
        int hd = it.second;
        
        if (hdMap.find(hd) == hdMap.end()) {
            hdMap[hd] = node->data;
        }
        
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }
    
    for (auto it : hdMap) {
        ans.push_back(it.second);
    }
    
    return ans;
}

// Helper function to create a sample binary tree
Node* createSampleTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = createSampleTree();
    vector<int> result = topView(root);
    
    cout << "Top View of Binary Tree: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}