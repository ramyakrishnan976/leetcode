#include <stdio.h>

int wiggleMaxLength(int* nums, int numsSize) {
    // Step 1: Handle tiny arrays safely
    if (numsSize < 2) {
        return numsSize;
    }

    // A sequence with at least one element starts with a base length of 1
    int max_length = 1;
    int prev_diff = 0;

    // Step 2: Linearly scan the differences between adjacent elements
    for (int i = 1; i < numsSize; i++) {
        int curr_diff = nums[i] - nums[i - 1];

        // Found a turning point moving upward (peak)
        if (curr_diff > 0 && prev_diff <= 0) {
            max_length++;
            prev_diff = curr_diff;
        }
        // Found a turning point moving downward (valley)
        else if (curr_diff < 0 && prev_diff >= 0) {
            max_length++;
            prev_diff = curr_diff;
        }
    }

    return max_length;
}
