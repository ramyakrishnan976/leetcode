#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro to find the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Allocate a 1D DP array initialized to zero
    int* dp = (int*)calloc(nums2Size + 1, sizeof(int));
    int maxLength = 0;

    // Traverse through each element of nums1
    for (int i = 1; i <= nums1Size; i++) {
        // Iterate backward to use values from the previous row without overwriting them
        for (int j = nums2Size; j >= 1; j--) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[j] = dp[j - 1] + 1;
                maxLength = MAX(maxLength, dp[j]);
            } else {
                // If elements do not match, the contiguous matching subarray breaks
                dp[j] = 0;
            }
        }
    }

    // Free the dynamically allocated buffer to prevent memory leaks
    free(dp);

    return maxLength;
}
