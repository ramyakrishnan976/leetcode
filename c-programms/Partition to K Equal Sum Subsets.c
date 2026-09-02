#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Comparison function to sort integers in ascending order
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool backtrack(int mask, int currentSum, int target, int* nums, int numsSize, bool* memo) {
    // Base Case: If all bits are set to 1, all numbers have been successfully partitioned
    if (mask == (1 << numsSize) - 1) {
        return true;
    }

    // Return false if this exact subset combination was already marked as a failed path
    if (!memo[mask]) {
        return false;
    }

    // If the current subset sum hits the target, reset to 0 to begin building the next subset
    if (currentSum == target) {
        return backtrack(mask, 0, target, nums, numsSize, memo);
    }

    // Try to include each unvisited element into the current subset (from largest to smallest)
    for (int i = numsSize - 1; i >= 0; i--) {
        // Check if the i-th element has NOT been used yet
        if (!(mask & (1 << i))) {
            // Pruning: Since the array is sorted, if this element exceeds the target,
            // smaller elements might still fit, so we continue checking.
            if (currentSum + nums[i] > target) {
                continue;
            }

            // Move forward by setting the i-th bit in our mask
            if (backtrack(mask | (1 << i), currentSum + nums[i], target, nums, numsSize, memo)) {
                return true;
            }
        }
    }

    // Mark this configuration mask as a failed state to prune future redundant lookups
    memo[mask] = false;
    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    // If total sum isn't perfectly divisible by k, equal groups are impossible
    if (totalSum % k != 0) {
        return false;
    }

    int target = totalSum / k;

    // Sort the array to ensure efficient pruning paths
    qsort(nums, numsSize, sizeof(int), compare);

    // If the single largest element exceeds the target subset size, it cannot fit anywhere
    if (nums[numsSize - 1] > target) {
        return false;
    }

    // Allocate memo array for 2^n states
    int numStates = 1 << numsSize;
    bool* memo = (bool*)malloc(numStates * sizeof(bool));
    // Initialize memo array to true (meaning the state hasn't been marked as a failure yet)
    memset(memo, true, numStates * sizeof(bool));

    bool result = backtrack(0, 0, target, nums, numsSize, memo);

    free(memo); // Free allocated memory to eliminate leaks
    return result;
}
