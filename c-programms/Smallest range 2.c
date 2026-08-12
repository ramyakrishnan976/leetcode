#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Helper macros to find min and max
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int smallestRangeII(int* nums, int numsSize, int k) {
    // If there is only one element, the difference is always 0
    if (numsSize <= 1) {
        return 0;
    }

    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initial score without splitting (everything shifted up or down equally)
    int initial_ans = nums[numsSize - 1] - nums[0];
    int ans = initial_ans;

    // Step 2: Traverse possible split points i
    // Elements from index 0 to i are increased (+k)
    // Elements from index i+1 to numsSize-1 are decreased (-k)
    for (int i = 0; i < numsSize - 1; i++) {
        int current_max = MAX(nums[numsSize - 1] - k, nums[i] + k);
        int current_min = MIN(nums[0] + k, nums[i + 1] - k);
        
        ans = MIN(ans, current_max - current_min);
    }

    return ans;
}
