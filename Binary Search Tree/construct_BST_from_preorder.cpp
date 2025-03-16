// Construct BST from preorder traversal (LC: 1008)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    BinaryTreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

BinaryTreeNode* solve(vector<int>& preOrder, int mini, int maxi, int& i) {
    if (i >= preOrder.size()) {
        return nullptr;
    }

    if (preOrder[i] < mini || preOrder[i] > maxi) {
        return nullptr;
    }

    BinaryTreeNode* root = new BinaryTreeNode(preOrder[i++]);
    root->left = solve(preOrder, mini, root->data, i);
    root->right = solve(preOrder, root->data, maxi, i);

    return root;
}

BinaryTreeNode* preorderToBST(vector<int>& preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}

void printInOrder(BinaryTreeNode* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    
    BinaryTreeNode* root = preorderToBST(preorder);
    
    cout << "InOrder Traversal of Constructed BST: ";
    printInOrder(root);
    cout << endl;
    
    return 0;
}