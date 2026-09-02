#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize) {
    // Set the return size to 3 as we need exactly 3 starting indices
    *returnSize = 3;
    int* result = (int*)malloc(3 * sizeof(int));
    
    int numWindows = numsSize - k + 1;
    int* sums = (int*)malloc(numWindows * sizeof(int));
    int* left = (int*)malloc(numWindows * sizeof(int));
    int* right = (int*)malloc(numWindows * sizeof(int));
    
    // Step 1: Precompute sums of all subarrays of length k using a sliding window
    int currentSum = 0;
    for (int i = 0; i < numsSize; i++) {
        currentSum += nums[i];
        if (i >= k) {
            currentSum -= nums[i - k];
        }
        if (i >= k - 1) {
            sums[i - k + 1] = currentSum;
        }
    }
    
    // Step 2: Build the left array (best window index from 0 to i)
    int bestLeftIdx = 0;
    for (int i = 0; i < numWindows; i++) {
        if (sums[i] > sums[bestLeftIdx]) {
            bestLeftIdx = i;
        }
        left[i] = bestLeftIdx;
    }
    
    // Step 3: Build the right array (best window index from i to end)
    int bestRightIdx = numWindows - 1;
    for (int i = numWindows - 1; i >= 0; i--) {
        // Use >= to favor smaller indices in case of a tie for lexicographical ordering
        if (sums[i] >= sums[bestRightIdx]) {
            bestRightIdx = i;
        }
        right[i] = bestRightIdx;
    }
    
    // Step 4: Sweep through all valid middle window indices and maximize total sum
    int maxTotalSum = -1;
    
    // The middle window index 'i' must leave room for the left window (at least k elements before)
    // and the right window (at least k elements after)
    for (int i = k; i < numWindows - k; i++) {
        int lIdx = left[i - k];
        int rIdx = right[i + k];
        int totalSum = sums[lIdx] + sums[i] + sums[rIdx];
        
        if (totalSum > maxTotalSum) {
            maxTotalSum = totalSum;
            result[0] = lIdx;
            result[1] = i;
            result[2] = rIdx;
        }
    }
    
    // Free all dynamically allocated temporary arrays
    free(sums);
    free(left);
    free(right);
    
    return result;
}
