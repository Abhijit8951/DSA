#include <iostream>
#include<map>
using namespace std;

// Definition of a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to create parent mapping and find target node
Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
    Node* res = NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front->data == target) {
            res = front;
        }

        if (front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if (front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

// Function to calculate the time to burn the tree
int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
    map<Node*, bool> visited;
    queue<Node*> q;
    
    q.push(root);
    visited[root] = true;
    
    int ans = 0;
    while (!q.empty()) {
        bool flag = false;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();

            if (front->left && !visited[front->left]) {
                flag = true;
                q.push(front->left);
                visited[front->left] = true;
            }

            if (front->right && !visited[front->right]) {
                flag = true;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodeToParent.find(front) != nodeToParent.end() && nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        if (flag) {
            ans++;
        }
    }
    return ans;
}

// Function to return minimum time to burn the tree from a target node
int minTime(Node* root, int target) {
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    
    return burnTree(targetNode, nodeToParent);
}

Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    
    return root;
}

int main() {
    Node* root = buildTree();
    int target = 3;

    cout << "Minimum time to burn tree: " << minTime(root, target) << endl;

    return 0;
}