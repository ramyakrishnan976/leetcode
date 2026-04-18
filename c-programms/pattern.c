#include <stdbool.h>
#include <limits.h>

bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) return false;

    int stack[numsSize];
    int top = -1;
    
    // This represents nums[k], the "2" in the "132" pattern.
    // It should be the largest possible value that has a larger value (nums[j]) to its left.
    int s3 = INT_MIN;

    for (int i = numsSize - 1; i >= 0; i--) {
        // If we find nums[i] < nums[k], and we know nums[k] < nums[j], pattern found!
        if (nums[i] < s3) return true;

        // Maintain a monotonic decreasing stack
        // If current element is larger than stack top, it's a potential nums[j]
        while (top >= 0 && nums[i] > stack[top]) {
            s3 = stack[top--]; // The popped value becomes our "2" (nums[k])
        }

        // Push current element as a potential nums[j]
        stack[++top] = nums[i];
    }

    return false;
}
