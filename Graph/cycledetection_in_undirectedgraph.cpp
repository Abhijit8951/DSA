// Cycle detection in undirected graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// BFS-based cycle detection
bool isCyclicBFS(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front]) {
            if (visited[neighbour] && neighbour != parent[front]) {
                return true;
            } else if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }

    return false;
}

// DFS-based cycle detection
bool isCyclicDFS(int node, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclicDFS(neighbour, node, visited, adj)) {
                return true;
            }
        } else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

// Cycle detection using BFS
string cycleDetectionBFS(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicBFS(i, visited, adj)) {
                return "Yes";
            }
        }
    }

    return "No";
}

// Cycle detection using DFS
string cycleDetectionDFS(vector<vector<int>>& edges, int n, int m) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, visited, adj)) {
                return "Yes";
            }
        }
    }

    return "No";
}

int main() {
    // Sample input
    int n = 5; // number of nodes
    int m = 5; // number of edges

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 1}  // This edge creates a cycle
    };

    cout << "Cycle detection using BFS: " << cycleDetectionBFS(edges, n, m) << endl;
    cout << "Cycle detection using DFS: " << cycleDetectionDFS(edges, n, m) << endl;

    return 0;
}