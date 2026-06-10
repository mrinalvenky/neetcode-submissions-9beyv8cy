class Solution {
private:
    class DisjointSetUnion {
        private:
            vector<int> parent, rank;
            int numComponents;
        public:
            DisjointSetUnion(int n) {
                numComponents = n;
                for (int i = 0; i < n ; i++) {
                    parent.push_back(i);
                    rank.push_back(0);
                }
            }
            int find(int x) {
                while(x != parent[x]) {
                    parent[x] = parent[parent[x]];
                    x = parent[x];
                }
                return x;
            }
            bool unite(int n1, int n2) {
                int p1 = find(n1);
                int p2 = find(n2);
                if (p1 == p2) return false;
                if (rank[p1] > rank[p2]) {
                    parent[p2] = p1;
                    rank[p1] += rank[p2];
                } else {
                    parent[p1] = p2;
                    rank[p2] += rank[p1];
                }
                numComponents--;
                return true;
            }
            int getNumComponents() {
                return numComponents;
            }
    };
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        DisjointSetUnion dsu(n);
        priority_queue<
            pair<int , pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > minHeap;
        for (const auto& edge : edges) {
            minHeap.push({edge[2], {edge[0], edge[1]}});
        }
        int totalWt = 0;
        while(!minHeap.empty()) {
            auto [wt, edge] = minHeap.top();
            minHeap.pop();
            if (!dsu.unite(edge.first, edge.second)) continue;
            totalWt += wt;
        }
        return dsu.getNumComponents() != 1 ? -1 : totalWt;
    }
};
