class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0) {
            return 0;
        }

        int m = grid.length;
        int n = grid[0].length;
        int islandCount = 0;

        // Traverse every cell in the 2D grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we hit land, it's the start of a new island
                if (grid[i][j] == '1') {
                    islandCount++;
                    // Run DFS to "sink" the entire island
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islandCount;
    }

    private void dfs(char[][] grid, int r, int c, int m, int n) {
        // Base case: check boundary limits and if the cell is water ('0')
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') {
            return;
        }

        // Mark the current land cell as visited by converting it to water
        grid[r][c] = '0';

        // Recursively visit all 4 neighboring directions
        dfs(grid, r - 1, c, m, n); // Up
        dfs(grid, r + 1, c, m, n); // Down
        dfs(grid, r, c - 1, m, n); // Left
        dfs(grid, r, c + 1, m, n); // Right
    }
}
