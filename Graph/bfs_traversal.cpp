// BFS traversal of graph
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>>& adj, vector<vector<int>> &edges) {
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];    
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adj[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &edges){
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adj, edges);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}

int main() {
    int n = 8;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 4}, {1, 7},
        {2, 5},
        {3, 6}
    };

    vector<int> result = bfsTraversal(n, edges);

    for(int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}