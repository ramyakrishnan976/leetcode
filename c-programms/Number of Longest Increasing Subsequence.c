#include <stdio.h>
#include <stdlib.h>

int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    // lengths[i] will store the length of the LIS ending at index i
    int* lengths = (int*)malloc(numsSize * sizeof(int));
    // counts[i] will store the number of LIS ending at index i
    int* counts = (int*)malloc(numsSize * sizeof(int));

    int max_len = 0;
    int total_lis_count = 0;

    // Initialize tracking arrays
    for (int i = 0; i < numsSize; i++) {
        lengths[i] = 1; // Every single element is an LIS of length 1
        counts[i] = 1;  // There is 1 way to form a sequence of length 1
    }

    // Build the DP tables
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                // If appending nums[i] to the LIS ending at j creates a longer LIS
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j]; // Inherit the number of ways from j
                } 
                // If appending nums[i] to the LIS ending at j forms an identical max length
                else if (lengths[j] + 1 == lengths[i]) {
                    counts[i] += counts[j]; // Accumulate alternative pathways
                }
            }
        }
        // Keep track of the global maximum LIS length found so far
        if (lengths[i] > max_len) {
            max_len = lengths[i];
        }
    }

    // Sum up counts of all subsequences that achieve the maximum global length
    for (int i = 0; i < numsSize; i++) {
        if (lengths[i] == max_len) {
            total_lis_count += counts[i];
        }
    }

    // Clean up allocated memory blocks
    free(lengths);
    free(counts);

    return total_lis_count;
}
