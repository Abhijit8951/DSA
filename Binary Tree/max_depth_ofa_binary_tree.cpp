// Max depth of a binary tree
#include <iostream>
#include <algorithm>

using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the maximum depth of a binary tree
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = maxDepth(root->left);  // Corrected: Now calling left subtree
    int right = maxDepth(root->right); // Corrected: Now calling right subtree

    return max(left, right) + 1;
}

int main() {
    // Creating a sample tree
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    cout << "Maximum Depth of the Tree: " << maxDepth(root) << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}