#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int possibleStringCount(char* word, int k) {
    int n = strlen(word);
    
    // Group identical consecutive characters into count chunks
    int* counts = (int*)malloc(n * sizeof(int));
    int num_blocks = 0;
    
    long long total_combinations = 1;
    int current_run = 1;
    
    for (int i = 1; i <= n; i++) {
        if (word[i] == word[i - 1]) {
            current_run++;
        } else {
            counts[num_blocks++] = current_run;
            total_combinations = (total_combinations * current_run) % MOD;
            current_run = 1;
        }
    }
    
    // If k is less than or equal to the minimum possible length, all configurations are valid
    if (k <= num_blocks) {
        free(counts);
        return (int)total_combinations;
    }
    
    // dp[l] stores the number of ways to form an intended original string of length l
    long long* dp = (long long*)calloc(k, sizeof(long long));
    long long* next_dp = (long long*)calloc(k, sizeof(long long));
    long long* pref = (long long*)calloc(k + 1, sizeof(long long));
    
    // Base Case: 0 blocks can form a string of length 0 in exactly 1 way
    dp[0] = 1;
    
    // Process block by block
    for (int b = 0; b < num_blocks; b++) {
        int c = counts[b];
        
        // Build the complete prefix sum array for the current DP row up to size k
        pref[0] = 0;
        for (int i = 0; i < k; i++) {
            pref[i + 1] = (pref[i] + dp[i]) % MOD;
        }
        
        // Reset the next DP row layout
        memset(next_dp, 0, k * sizeof(long long));
        
        // Calculate new combination states using O(1) sliding prefix ranges
        for (int len = 0; len < k; len++) {
            int low = len - c;
            int high = len - 1;
            if (low < 0) low = 0;
            
            if (low <= high) {
                next_dp[len] = (pref[high + 1] - pref[low] + MOD) % MOD;
            }
        }
        
        // Advance row reference values forward
        memcpy(dp, next_dp, k * sizeof(long long));
    }
    
    // Accumulate all generated paths whose total lengths are strictly less than k
    long long invalid_combinations = 0;
    for (int len = 0; len < k; len++) {
        invalid_combinations = (invalid_combinations + dp[len]) % MOD;
    }
    
    // The valid combinations count is (Total Configurations) - (Invalid Configurations < k)
    long long result = (total_combinations - invalid_combinations + MOD) % MOD;
    
    // Clean up allocated dynamic frames
    free(counts);
    free(dp);
    free(next_dp);
    free(pref);
    
    return (int)result;
}
