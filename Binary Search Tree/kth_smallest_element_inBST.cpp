// Kth smallest elementt in BST
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode* root, int &i, int k) {
    if(root == NULL) {
        return -1;
    }

    int left = solve(root->left, i, k);

    if(left != -1) {
        return left;
    }

    i++;
    if(i == k) {
        return root->val;
    }

    return solve(root->right, i, k);
}

int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    return solve(root, i, k);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    
    int k = 2;
    cout << "The " << k << "th smallest element is " << kthSmallest(root, k) << endl;
    
    return 0;
}