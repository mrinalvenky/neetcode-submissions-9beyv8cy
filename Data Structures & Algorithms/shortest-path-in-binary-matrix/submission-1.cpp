class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (!grid.size() || !grid[0].size()) return 0;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;
        vector<pair<int, int>> dirs = {
            {0, 1}, {1, 0} , {0, -1}, {-1, 0},
            {1, 1}, {1, -1} , {-1, 1}, {-1, -1}
        };
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({0, 0});
        visited[0][0] = true;
        int dist = 1;
        while(!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto next = q.front();
                q.pop();
                if (next.first == n - 1 && next.second == n - 1) {
                    return dist;
                }
                for (auto& [dr, dc]: dirs) {
                    if ((next.first + dr >= 0 && next.first + dr < n) &&
                        (next.second + dc >= 0 && next.second + dc < n) &&
                        !visited[next.first + dr][next.second + dc] &&
                        !grid[next.first + dr][next.second + dc]) {
                            visited[next.first + dr][next.second + dc] = true;
                            q.push({next.first + dr, next.second + dc});
                        }
                }
            }
            dist++;
        }
        return -1;
    }
};