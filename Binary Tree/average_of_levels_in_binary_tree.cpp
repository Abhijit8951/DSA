// Average of levels in binary tree (LC: 637)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> result;
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            sum += node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(sum / size);
    }
    return result;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    vector<double> averages = averageOfLevels(root);
    
    cout << "Average of each level: ";
    for (double avg : averages) {
        cout << avg << " ";
    }
    cout << endl;
    
    return 0;
}