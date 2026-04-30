class Solution {
    public int uniquePaths(int m, int n) {
        // Create a 2D DP table
        int[][] dp = new int[m][n];

        // Fill the first row and first column with 1
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;

        // Fill the rest of the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // Ways to current cell = ways from Top + ways from Left
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // The answer is in the bottom-right corner
        return dp[m - 1][n - 1];
    }
}
