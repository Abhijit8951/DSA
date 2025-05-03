// DFS traversal of graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < E; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // Call DFS for each unvisited node
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }

    return ans;
}

// Example usage
int main() {
    int V = 8;
    int E = 7;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 4}, {1, 7},
        {2, 5},
        {3, 6}
    };

    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    cout << "DFS Components:\n";
    for (const auto& comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}