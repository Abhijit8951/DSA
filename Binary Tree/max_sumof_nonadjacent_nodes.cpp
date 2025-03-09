// Maximum sum of Non-adjacent node
// Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that the sum of chosen nodes is maximum under a constraint that no two chosen nodes in the subset should be directly connected that is, if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.
#include <iostream>
#include <utility>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

pair<int, int> solve(Node* root) {
    if (root == NULL) {
        return {0, 0};
    }
    
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    
    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    
    return res;
}

int getMaxSum(Node* root) {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    
    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;
    
    return 0;
}