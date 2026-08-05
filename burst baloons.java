class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        
        // Create a new array with padded 1s at the boundaries
        int[] paddedNums = new int[n + 2];
        paddedNums[0] = 1;
        paddedNums[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            paddedNums[i + 1] = nums[i];
        }
        
        // dp[left][right] stores the max coins obtainable from bursting balloons in range [left, right]
        int[][] dp = new int[n + 2][n + 2];
        
        // Iterate over all possible window lengths (from 1 to n)
        for (int length = 1; length <= n; length++) {
            // Iterate over all valid starting points for the given window length
            for (int left = 1; left <= n - length + 1; left++) {
                int right = left + length - 1;
                
                // Try every balloon 'i' in the range [left, right] as the LAST one to burst
                for (int i = left; i <= right; i++) {
                    int coins = paddedNums[left - 1] * paddedNums[i] * paddedNums[right + 1];
                    
                    // Total coins = coins from left sub-problem + current coins + coins from right sub-problem
                    int total = dp[left][i - 1] + coins + dp[i + 1][right];
                    
                    dp[left][right] = Math.max(dp[left][right], total);
                }
            }
        }
        
        return dp[1][n];
    }
}
