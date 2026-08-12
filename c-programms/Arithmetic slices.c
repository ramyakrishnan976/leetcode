#include <stdio.h>

int numberOfArithmeticSlices(int* nums, int numsSize) {
    // Step 1: Subarrays must have at least 3 elements
    if (numsSize < 3) {
        return 0;
    }
    
    int total_slices = 0;
    int current_slices = 0;
    
    // Step 2: Linearly check consecutive differences starting from the third element
    for (int i = 2; i < numsSize; i++) {
        // Check if the common difference is maintained
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
            current_slices++;
            total_slices += current_slices;
        } else {
            // The chain is broken; reset the consecutive count
            current_slices = 0;
        }
    }
    
    return total_slices;
}
