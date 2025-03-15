// Two sum in BST
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

void inOrder(TreeNode* root, vector<int>& inOrderVal) {
    if (root == nullptr) return;
    
    inOrder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}

bool twoSumInBST(TreeNode* root, int target) {
    vector<int> inOrderVal;
    inOrder(root, inOrderVal);
    
    int i = 0, j = inOrderVal.size() - 1;
    
    while (i < j) {
        int sum = inOrderVal[i] + inOrderVal[j];
        
        if (sum == target) {
            return true;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    // Creating a simple BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    
    int target = 9;
    if (twoSumInBST(root, target)) {
        cout << "Pair with given sum exists in BST" << endl;
    } else {
        cout << "No such pair exists" << endl;
    }
    
    return 0;
}