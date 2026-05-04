class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int node) {
        int cur = node;
        while (cur != parent[cur]) {
            parent[cur] = parent[parent[cur]];
            cur = parent[cur];
        }
        return cur;
    }
    bool unionSet(int n1, int n2) {
        int p1 = find(n1), p2 = find(n2);
        if (p1 == p2) {
            return false;
        }
        if (rank[p1] < rank[p2]) {
            parent[p2] = p1;
            rank[p2] += rank[p1];
        } else {
            parent[p1] = p2;
            rank[p1] += rank[p2];
        }
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n ; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
        int result = n;
        for (auto& e: edges) {
            if (unionSet(e[0], e[1])) {
                result--;
            }
        }
        return result;
    }
};
