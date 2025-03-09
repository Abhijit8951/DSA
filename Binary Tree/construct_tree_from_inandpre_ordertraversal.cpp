// Construct tree from inorder and preorder traversal
// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findPosition(vector<int>& in, int element, int n) {
    for (int i = 0; i < n; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

TreeNode* solve(vector<int>& in, vector<int>& pre, int& index, int inOrderStart, int inOrderEnd, int n) {
    if (index >= n || inOrderStart > inOrderEnd) {
        return NULL;
    }
    
    int element = pre[index++];
    TreeNode* root = new TreeNode(element);
    int position = findPosition(in, element, n);
    
    root->left = solve(in, pre, index, inOrderStart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inOrderEnd, n);
    
    return root;
}

TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int preOrderIndex = 0;
    return solve(in, pre, preOrderIndex, 0, pre.size() - 1, pre.size());
}

void printPostorder(TreeNode* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    
    TreeNode* root = buildTree(pre, in);
    
    cout << "Postorder traversal of constructed tree: ";
    printPostorder(root);
    cout << endl;
    
    return 0;
}