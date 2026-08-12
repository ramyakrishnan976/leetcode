#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Traverse the array from the least significant digit (right to left)
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            
            // Allocate memory for the output array of the same size
            int* result = (int*)malloc(digitsSize * sizeof(int));
            for (int j = 0; j < digitsSize; j++) {
                result[j] = digits[j];
            }
            *returnSize = digitsSize;
            return result;
        }
        // If the digit is 9, it carries over and becomes 0
        digits[i] = 0;
    }
    
    // If the loop finishes, all digits were 9 (e.g., 999 -> 1000)
    *returnSize = digitsSize + 1;
    int* result = (int*)malloc((*returnSize) * sizeof(int));
    
    // The most significant digit becomes 1, followed by all 0s
    result[0] = 1;
    for (int j = 1; j < *returnSize; j++) {
        result[j] = 0;
    }
    
    return result;
}
