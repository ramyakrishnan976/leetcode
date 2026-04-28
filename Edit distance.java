class Solution {
    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] is the distance between word1[0...i-1] and word2[0...j-1]
        int[][] dp = new int[m + 1][n + 1];
        
        // Base cases: converting a string to an empty string requires i deletions
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    // Characters match, no new operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters don't match, take the min of:
                    // 1. Replace (diagonal: dp[i-1][j-1])
                    // 2. Insert (left: dp[i][j-1])
                    // 3. Delete (up: dp[i-1][j])
                    dp[i][j] = 1 + Math.min(dp[i - 1][j - 1], 
                                   Math.min(dp[i][j - 1], dp[i - 1][j]));
                }
            }
        }
        
        return dp[m][n];
    }
}
