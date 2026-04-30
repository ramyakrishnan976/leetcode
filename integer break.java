class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        // Base case
        dp[1] = 1; 

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // We compare:
                // 1. The current dp[i]
                // 2. j * (i-j) -> breaking i into exactly two parts
                // 3. j * dp[i-j] -> breaking i into j and then the best break of (i-j)
                int currentMax = Math.max(j * (i - j), j * dp[i - j]);
                dp[i] = Math.max(dp[i], currentMax);
            }
        }
        return dp[n];
    }
}
