// reverse level order(LC: 107)
// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Reverse Level Order Traversal without using vectors
void levelOrderBottom(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    stack<TreeNode*> s;  // To store nodes in reverse order
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        s.push(node);

        // Push right child first, then left (for correct order)
        if (node->right) q.push(node->right);
        if (node->left) q.push(node->left);
    }

    // Print stack contents in reverse level order
    while (!s.empty()) {
        cout << s.top()->val << " ";
        s.pop();
    }
    cout << endl;
}

// Function to build a binary tree
TreeNode* buildTree() {
    int data;
    cout << "Enter node value (-1 for NULL): ";
    cin >> data;
    if (data == -1) return NULL;

    TreeNode* root = new TreeNode(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();
    return root;
}

int main() {
    TreeNode* root = buildTree();

    cout << "Reverse Level Order Traversal: " << endl;
    levelOrderBottom(root);

    return 0;
}