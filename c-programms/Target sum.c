#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findTargetSumWays(int* nums, int numsSize, int target) {
    int total_sum = 0;
    for (int i = 0; i < numsSize; i++) {
        total_sum += nums[i];
    }

    // Step 1: Check if the mathematical transformation is valid
    if (target + total_sum < 0 || (target + total_sum) % 2 != 0) {
        return 0;
    }

    int subset_target = (target + total_sum) / 2;

    // Step 2: Initialize a 1D DP array of size subset_target + 1
    int* dp = (int*)calloc(subset_target + 1, sizeof(int));
    dp[0] = 1; // Base case: There is 1 way to form a sum of 0 (empty subset)

    // Step 3: Run the 0-1 Knapsack bottom-up update loop
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        // Iterate backwards to avoid using the same element multiple times
        for (int j = subset_target; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    int result = dp[subset_target];
    free(dp); // Clean up dynamically allocated memory

    return result;
}
