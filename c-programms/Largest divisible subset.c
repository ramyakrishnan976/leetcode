#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    return (valA > valB) - (valA < valB);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    // Arrays to store DP sizes and backtracking parent pointers
    int* dp = (int*)malloc(numsSize * sizeof(int));
    int* parent = (int*)malloc(numsSize * sizeof(int));

    int max_size = 1;
    int max_index = 0;

    // Step 2: Initialize arrays
    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        parent[i] = -1;
    }

    // Step 3: Populate the DP table
    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            // Check divisibility and path length optimization
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        // Track the absolute maximum subset size found
        if (dp[i] > max_size) {
            max_size = dp[i];
            max_index = i;
        }
    }

    // Step 4: Reconstruct the largest subset using parent pointers
    *returnSize = max_size;
    int* result = (int*)malloc(max_size * sizeof(int));
    
    int curr = max_index;
    for (int i = max_size - 1; i >= 0; i--) {
        result[i] = nums[curr];
        curr = parent[curr];
    }

    // Free local dynamic tracking pools
    free(dp);
    free(parent);

    return result;
}
