// Largest BST in binary tree
#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
    
    Info(int maxVal, int minVal, bool bst, int sz) {
        maxi = maxVal;
        mini = minVal;
        isBST = bst;
        size = sz;
    }
};

Info solve(TreeNode* root, int &ans) {
    if (root == nullptr) {
        return Info(INT_MIN, INT_MAX, true, 0);
    }

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info currNode(
        max(root->data, right.maxi), 
        min(root->data, left.mini), 
        left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini), 
        left.size + right.size + 1
    );

    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode* root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    cout << "Size of largest BST: " << largestBST(root) << endl;

    return 0;
}