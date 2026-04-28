class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;

        // If the start or end is an obstacle, no path is possible
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }

        int[][] dp = new int[m][n];
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is an obstacle, skip it (paths remain 0)
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                
                // Add paths from the top
                if (i > 0) dp[i][j] += dp[i - 1][j];
                // Add paths from the left
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
}
