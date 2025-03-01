// ZigZag Tree Traversal
// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
// In zig zag traversal starting from the first level go from left to right for odd-numbered levels and right to left for even-numbered levels.
// Examples:
// Input:
//         1
//       /   \
//      2      3
//     / \    /  \
//    4   5  6    7
// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// For level 1 going left to right, we get traversal as {1}.
// For level 2 going right to left, we get traversal as {3,2}.
// For level 3 going left to right, we get traversal as {4,5,6,7}.
// Merging all this traversals in single array we get {1,3,2,4,5,6,7}.
#include <iostream>
#include <vector>
#include <queue>

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

vector<int> zigZagTraversal(Node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    
    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
        
        for (int i = 0; i < size; i++) {
            Node* frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;
            
            if (frontNode->left) {
                q.push(frontNode->left);
            }
            
            if (frontNode->right) {
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;
        
        for (auto i : ans) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    vector<int> result = zigZagTraversal(root);
    
    cout << "ZigZag Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}