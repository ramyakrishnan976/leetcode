#include <stdio.h>
#include <stdlib.h>

#define OFFSET 10000

int arrayPairSum(int* nums, int numsSize) {
    // The range of nums[i] is [-10000, 10000].
    // Size = 10000 (negative) + 1 (zero) + 10000 (positive) = 20001 slots.
    int count[20005] = {0};
    
    // Step 1: Populate frequencies of each element
    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + OFFSET]++;
    }
    
    int max_sum = 0;
    int residue = 0; // Tracks if an element needs to pair across buckets
    
    // Step 2: Iterate through the bucket array sequentially (inherently sorted)
    for (int i = 0; i <= 20000; i++) {
        while (count[i] > 0) {
            // Reconstruct the actual number from the index
            int actual_value = i - OFFSET;
            
            if (residue == 1) {
                // This element acts as the 'second' item in a pair, so its value is discarded
                count[i]--;
                residue = 0;
            } else {
                // This element acts as the 'first' item in a pair, add it to our max_sum
                max_sum += actual_value;
                count[i]--;
                residue = 1;
            }
        }
    }
    
    return max_sum;
}
