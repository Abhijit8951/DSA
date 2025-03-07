// K sum paths
// Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).
#include <iostream>
#include <unordered_map>
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

// Function to count the number of paths that sum to k
void solve(Node* root, int k, int currSum, unordered_map<int, int>& prefixSum, int &count) {
    if (root == NULL) {
        return;
    }

    // Update current path sum
    currSum += root->data;

    // If the current sum itself is equal to k, increment count
    if (currSum == k) {
        count++;
    }

    // Check if there exists a prefix sum that forms a subarray sum of k
    if (prefixSum.find(currSum - k) != prefixSum.end()) {
        count += prefixSum[currSum - k];
    }

    // Store the current sum in the map
    prefixSum[currSum]++;

    // Recursive calls for left and right subtree
    solve(root->left, k, currSum, prefixSum, count);
    solve(root->right, k, currSum, prefixSum, count);

    // Backtrack: Remove the current sum from the map
    prefixSum[currSum]--;
}

// Function to count paths that sum to k
int sumK(Node* root, int k) {
    unordered_map<int, int> prefixSum;
    int count = 0;
    solve(root, k, 0, prefixSum, count);
    return count;
}

// Function to create a sample binary tree
Node* createTree() {
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->right->left = new Node(1);
    return root;
}

int main() {
    Node* root = createTree();
    int k = 4;

    cout << "Number of paths with sum " << k << " is: " << sumK(root, k) << endl;

    return 0;
}