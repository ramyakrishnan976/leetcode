#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro to find the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // Given the constraint 1 <= nums[i] <= 10^4
    int max_val = 10001;
    int* sums = (int*)calloc(max_val, sizeof(int));

    // Step 1: Accumulate total possible points for each distinct value
    for (int i = 0; i < numsSize; i++) {
        sums[nums[i]] += nums[i];
    }

    // Step 2: Apply the space-optimized House Robber logic
    int prev2 = 0; // Represents state for i - 2
    int prev1 = 0; // Represents state for i - 1

    for (int i = 0; i < max_val; i++) {
        int current = MAX(prev1, prev2 + sums[i]);
        prev2 = prev1;
        prev1 = current;
    }

    // Clean up allocated buffer memory
    free(sums);

    return prev1;
}
