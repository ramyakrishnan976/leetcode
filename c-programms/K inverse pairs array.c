#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kInversePairs(int n, int k) {
    int MOD = 1000000007;
    
    // We only need two rows for DP since row 'i' depends strictly on row 'i-1'
    int* dp = (int*)calloc(k + 1, sizeof(int));
    int* next_dp = (int*)calloc(k + 1, sizeof(int));
    
    // Base case: There is exactly 1 way to arrange a sequence with 0 inverse pairs
    dp[0] = 1;
    
    // Iteratively build up array size from 1 to n
    for (int i = 1; i <= n; i++) {
        long long val = 0; // Use long long to safely avoid overflow during modulo operations
        
        for (int j = 0; j <= k; j++) {
            // Add the new state contribution from the previous array size row
            val = (val + dp[j]) % MOD;
            
            // Maintain a sliding window of size 'i'.
            // If the window shifts past the element at index (j - i), subtract it.
            if (j >= i) {
                val = (val - dp[j - i] + MOD) % MOD;
            }
            
            next_dp[j] = (int)val;
        }
        
        // Copy next_dp contents to dp to serve as the baseline for the next iteration
        memcpy(dp, next_dp, (k + 1) * sizeof(int));
    }
    
    int result = dp[k];
    
    // Free dynamically allocated arrays to prevent memory leaks
    free(dp);
    free(next_dp);
    
    return result;
}
