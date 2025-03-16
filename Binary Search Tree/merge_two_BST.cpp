#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder traversal to get sorted values
void inorder(TreeNode* root, vector<int> &result) {
    if (!root) return;
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

// Merge two sorted arrays
vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j])
            merged.push_back(arr1[i++]);
        else
            merged.push_back(arr2[j++]);
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    return merged;
}

// Convert sorted array to balanced BST
TreeNode* inOrderToBST(int s, int e, vector<int>& inOrderval) {
    if (s > e) {
        return nullptr;
    }
    
    int mid = (s + e) / 2;
    
    TreeNode* root = new TreeNode(inOrderval[mid]);
    root->left = inOrderToBST(s, mid - 1, inOrderval);
    root->right = inOrderToBST(mid + 1, e, inOrderval);
    
    return root;
}

// Merge two BSTs into one balanced BST
TreeNode* mergeBST(TreeNode *root1, TreeNode *root2) {
    vector<int> bst1, bst2;
    
    // Get inorder traversal (sorted arrays)
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    // Merge both sorted arrays
    vector<int> merged = mergeSortedArrays(bst1, bst2);
    
    // Convert merged sorted array into a balanced BST
    return inOrderToBST(0, merged.size() - 1, merged);
}

// Helper function to print inorder traversal of BST
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(0);
    root2->right = new TreeNode(5);
    
    TreeNode* mergedRoot = mergeBST(root1, root2);
    
    cout << "Inorder Traversal of Merged BST: ";
    printInorder(mergedRoot);
    cout << endl;
    
    return 0;
}