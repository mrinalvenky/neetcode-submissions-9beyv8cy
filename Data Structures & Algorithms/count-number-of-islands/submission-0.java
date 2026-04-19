class Solution {
    private void dfs(char[][] grid, int row, int col, Set<List<Integer>> visited) {
        int rows = grid.length;
        int cols = grid[0].length;
        if (row >= rows || col >= cols || row < 0 || col < 0) {
            return;
        }
        if ((grid[row][col] == '0') || (visited.contains(Arrays.asList(row, col)))) {
            return;
        }
        visited.add(Arrays.asList(row, col));
        dfs(grid, row + 1, col, visited);
        dfs(grid, row - 1, col, visited);
        dfs(grid, row, col + 1, visited);
        dfs(grid, row, col - 1, visited);
    }
    public int numIslands(char[][] grid) {
        int count = 0;
        Set<List<Integer>> visited = new HashSet<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1' && !visited.contains(Arrays.asList(i, j))) {
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;
    }
}
