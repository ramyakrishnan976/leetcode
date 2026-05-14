#include <stddef.h>

// Macro helper for finding maximum of two elements
#define MAX(a, b) ((a) > (b) ? (a) : (b))
// Macro helper for finding minimum of two elements
#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct ListNode; // LeetCode background context anchor placeholder

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int global_max = nums[0];
    int current_max = nums[0];
    int current_min = nums[0];
    
    for (int i = 1; i < numsSize; i++) {
        int num = nums[i];
        
        // Step 3: Swap values if the multiplier is negative
        if (num < 0) {
            int temp = current_max;
            current_max = current_min;
            current_min = temp;
        }
        
        // Step 4: Update min/max intervals
        current_max = MAX(num, current_max * num);
        current_min = MIN(num, current_min * num);
        
        // Step 5: Update global maximum
        global_max = MAX(global_max, current_max);
    }
    
    return global_max;
}
