class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
        if (visited.count(node)) return false;
        visited.insert(node);
        for (int nei: adj[node]) {
            if (nei == parent) continue;
            if (!dfs(nei, node, adj, visited)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) return true;
        if (edges.size() > n - 1) return false;
        vector<vector<int>> adj(n);
        unordered_set<int> visited;
        for (auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (!dfs(0, -1, adj, visited)) return false;
        return visited.size() == n;
    }
};
