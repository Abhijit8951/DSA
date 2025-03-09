// Construct Binary Tree from Inorder and Postorder
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void createMapping(vector<int>& in, map<int, int>& nodeToIndex, int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(vector<int>& in, vector<int>& post, int& index, int inOrderStart, int inOrderEnd, int n, map<int, int>& nodeToIndex) {
    if (index < 0 || inOrderStart > inOrderEnd) {
        return NULL;
    }
    
    int element = post[index--];
    Node* root = new Node(element);
    int position = nodeToIndex[element];
    
    root->right = solve(in, post, index, position + 1, inOrderEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inOrderStart, position - 1, n, nodeToIndex);
    
    return root;
}

Node* buildTree(vector<int>& in, vector<int>& post) {
    int n = in.size();
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    
    createMapping(in, nodeToIndex, n);
    
    return solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> in = {4, 2, 5, 1, 6, 3, 7};
    vector<int> post = {4, 5, 2, 6, 7, 3, 1};
    
    Node* root = buildTree(in, post);
    
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;
    
    return 0;
}