#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Standard Euclidean Algorithm to find Greatest Common Divisor
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int subsequencePairCount(int* nums, int numsSize) {
    // Determine the maximum element bound in the array (at most 200)
    int max_val = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
    }
    
    int limit = max_val + 1;
    
    // Allocate space-optimized 2D grids representing row states
    // dp[g1][g2] stores combinations with current GCDs g1 and g2
    int** dp = (int**)malloc(limit * sizeof(int*));
    int** next_dp = (int**)malloc(limit * sizeof(int*));
    for (int i = 0; i < limit; i++) {
        dp[i] = (int*)calloc(limit, sizeof(int));
        next_dp[i] = (int*)calloc(limit, sizeof(int));
    }
    
    // Base Case: 1 way to have both subsequences empty (gcd = 0)
    dp[0][0] = 1;
    
    // Process each element in the input array sequentially
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        
        // Deep copy current DP state layer into the next buffer layer (handles 'Skip x' choice)
        for (int g1 = 0; g1 < limit; g1++) {
            memcpy(next_dp[g1], dp[g1], limit * sizeof(int));
        }
        
        // Evaluate transitions from previous configurations
        for (int g1 = 0; g1 < limit; g1++) {
            for (int g2 = 0; g2 < limit; g2++) {
                if (dp[g1][g2] == 0) continue;
                
                // Choice 1: Add x to the first subsequence (seq1)
                int n_g1 = (g1 == 0) ? x : gcd(g1, x);
                next_dp[n_g1][g2] = (next_dp[n_g1][g2] + dp[g1][g2]) % MOD;
                
                // Choice 2: Add x to the second subsequence (seq2)
                int n_g2 = (g2 == 0) ? x : gcd(g2, x);
                next_dp[g1][n_g2] = (next_dp[g1][n_g2] + dp[g1][g2]) % MOD;
            }
        }
        
        // Pointer swap row matrices to transition cleanly to the next item iteration
        int** temp = dp;
        dp = next_dp;
        next_dp = temp;
    }
    
    // Accumulate all combinations where both non-empty subsequences share identical GCDs
    long long total_pairs = 0;
    for (int g = 1; g < limit; g++) {
        total_pairs = (total_pairs + dp[g][g]) % MOD;
    }
    
    // Free dynamically allocated tracking arrays
    for (int i = 0; i < limit; i++) {
        free(dp[i]);
        free(next_dp[i]);
    }
    free(dp);
    free(next_dp);
    
    return (int)total_pairs;
}
