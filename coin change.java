import java.util.Arrays;

class Solution {
    public int coinChange(int[] coins, int amount) {
        // Initialize DP table with a value larger than any possible answer
        int max = amount + 1;
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, max);
        
        // Base case: 0 coins needed for amount 0
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) {
                    // Current amount i minus this coin's value + 1 (the coin itself)
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If dp[amount] is still max, it's impossible to make that amount
        return dp[amount] > amount ? -1 : dp[amount];
    }
}
