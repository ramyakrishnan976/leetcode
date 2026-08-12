#include <stdio.h>
#include <stdlib.h>

int change(int amount, int* coins, int coinsSize) {
    // Allocate a 1D DP buffer initialized to 0 using calloc
    int* dp = (int*)calloc(amount + 1, sizeof(int));
    
    // Base Case: 1 way to make an amount of 0 (using no coins)
    dp[0] = 1;
    
    // Outer Loop: Process each coin choice sequentially to prevent duplicate combinations
    for (int j = 0; j < coinsSize; j++) {
        int coin = coins[j];
        
        // Inner Loop: Update all target amounts from the coin's value up to the target amount
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    int result = dp[amount];
    free(dp); // Free dynamically allocated state memory
    
    return result;
}
