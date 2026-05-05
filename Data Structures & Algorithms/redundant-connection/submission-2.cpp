class Solution {
public:
    /*vector<int> parent;
    vector<int> rank;
    int find(int n) {
        while(n != parent[n]) {
            parent[n] = parent[parent[n]];
            n = parent[n];
        }
        return n;
    }
    bool unionSet(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) return false;
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        for (int i = 0; i < n + 1; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
        for (auto& e: edges) {
            if (!unionSet(e[0], e[1])) {
                return e;
            }
        }
        return {};
    }*/
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1, vector<int>());
        for (auto& e: edges) {
            indegree[e[0]]++;
            indegree[e[1]]++;
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int next = q.front();
            q.pop();
            for (int nei: adj[next]) {
                indegree[nei]--;
                if (indegree[nei] == 1) {
                    q.push(nei);
                }
            }
        }
        for (int i = edges.size() - 1; i >= 0; i--) {
            int a = edges[i][0], b = edges[i][1];
            if (indegree[a] > 1 && indegree[b] > 1) {
                return edges[i];
            }
        }
        return {};
    }
};
