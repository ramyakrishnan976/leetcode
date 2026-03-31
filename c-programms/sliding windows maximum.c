#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (numsSize == 0 || k == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    int* deque = (int*)malloc(numsSize * sizeof(int)); // Stores indices
    int head = 0, tail = 0;
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        // 1. Remove indices of elements smaller than current from the back
        while (tail > head && nums[deque[tail - 1]] <= nums[i]) {
            tail--;
        }
        
        // 2. Add current index
        deque[tail++] = i;

        // 3. Remove the index from the front if it's outside the window
        if (deque[head] <= i - k) {
            head++;
        }

        // 4. If window is full size, the front of deque is the current max
        if (i >= k - 1) {
            result[(*returnSize)++] = nums[deque[head]];
        }
    }

    free(deque);
    return result;
}
