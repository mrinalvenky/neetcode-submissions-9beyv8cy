class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size() + 1 , n = grid[0].size() + 1;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};