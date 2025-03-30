// Minimum depth of binary tree
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0; 

    queue<pair<TreeNode*, int>> q;  
    q.push(make_pair(root, 1));  // Start with the root node at depth 1
    
    while (!q.empty()) {
        pair<TreeNode*, int> front = q.front();  // Get the front node and its depth
        q.pop();
        TreeNode* node = front.first;
        int depth = front.second;
        
        if (node->left == nullptr && node->right == nullptr) {
            return depth;
        }
        
        if (node->left != nullptr) {
            q.push(make_pair(node->left, depth + 1));
        }
        
        if (node->right != nullptr) {
            q.push(make_pair(node->right, depth + 1));
        }
    }
    
    return 0; 
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "Minimum depth of the tree: " << minDepth(root) << endl;
    
    return 0;
}