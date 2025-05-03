// Cycle detection in directed graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

bool isCyclePresent(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsvisited, unordered_map<int, list<int>>& adj) {
    visited[node] = true;
    dfsvisited[node] = true;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            if (isCyclePresent(neighbour, visited, dfsvisited, adj)) {
                return true;
            }
        } else if (dfsvisited[neighbour]) {
            return true; // back edge found
        }
    }

    dfsvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;

    // Check for cycle in each component
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (isCyclePresent(i, visited, dfsvisited, adj)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n = 4;
    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}  // cycle exists
    };

    if (detectCycleInDirectedGraph(n, edges)) {
        cout << "Cycle detected in the directed graph" << endl;
    } else {
        cout << "No cycle in the directed graph" << endl;
    }

    return 0;
}