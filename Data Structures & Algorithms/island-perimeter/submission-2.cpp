class Solution {
public:
    int dfs(int row, int col, vector<vector<bool>>& visited, const vector<vector<int>>& grid) {
        if ( (row >= grid.size() || row < 0) ||
             (col >= grid[0].size() || col < 0) ||
             (grid[row][col] == 0)
           ) return 1;
        if (visited[row][col]) return 0;            
        visited[row][col] = true;

        return dfs(row + 1, col, visited, grid) + 
               dfs(row, col + 1, visited, grid) +
               dfs(row - 1, col, visited, grid) +
               dfs(row, col - 1, visited, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n  = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)  {
                    return dfs(i, j, visited, grid);
                }
            }
        }
        return 0;
    }
};