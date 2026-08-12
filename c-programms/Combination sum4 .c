#include <stdio.h>
#include <stdlib.h>

int combinationSum4(int* nums, int numsSize, int target) {
    // Dynamically allocate memory for our DP states up to target
    unsigned int* dp = (unsigned int*)calloc(target + 1, sizeof(unsigned int));
    
    // Base Case: One way to make a sum of 0 (using an empty sequence)
    dp[0] = 1;
    
    // Fill the DP table from 1 to target
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            int num = nums[j];
            
            // If the current target i can accommodate this number
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }
    
    int result = (int)dp[target];
    free(dp); // Free dynamically allocated tracking pool
    
    return result;
}
