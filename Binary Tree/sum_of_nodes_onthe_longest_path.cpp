// Sum of nodes on the longest path
// Given a binary tree root, you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.
// Examples:
// Input: root[] = [4, 2, 5, 7, 1, 1, 2, 3, N, 6]
// Output: 13
#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find the sum of the longest root-to-leaf path
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    if (root == NULL) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } else if (len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    sum += root->data;
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

int sumOfLongRootToLeafPath(Node* root) {
    int len = 0, maxLen = 0, sum = 0;
    int maxSum = INT_MIN;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}

int main() {
    // Creating a sample tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->right->right = new Node(6);
    root->left->right->left = new Node(3);
    
    cout << "Sum of the longest root-to-leaf path: " << sumOfLongRootToLeafPath(root) << endl;
    
    return 0;
}