class Solution {
public:
    vector<int> parent;
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
                // return {e[0], e[1]};
                return e;
            }
        }
        return {};
    }
};
