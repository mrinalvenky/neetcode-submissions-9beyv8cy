class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        if ((row >= ROWS || row < 0) ||
            (col >= COLS || col < 0) ||
            (grid[row][col] == 0)) return 0;
        grid[row][col] = 0;
        return 1 + dfs(row - 1, col, grid) +
                   dfs(row + 1, col, grid) +
                   dfs(row, col - 1, grid) +
                   dfs(row, col + 1, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j]) {
                   maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }
        return maxArea;
    }
};
