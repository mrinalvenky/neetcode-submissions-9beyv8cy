class Solution {
public:
    void dfs(int row, int col, vector<vector<bool>>& visited, const vector<vector<char>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        if ((row >= ROWS || row < 0) ||
            (col >= COLS || col < 0) ||
            (visited[row][col]) ||
            (grid[row][col] == '0')) return;
        visited[row][col] = true;
        vector<vector<int>> dir = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };
        for (auto& d : dir) {
            dfs(row + d[0], col + d[1], visited, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if ((grid[i][j] == '1') &&
                    (!visited[i][j])) {
                        dfs(i, j, visited, grid);
                        count++;
                }
            }
        }
        return count;
    }
};
