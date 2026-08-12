#include <stdio.h>
#include <stdlib.h>

// Helper function to reverse the prefix sub-array arr[0...k-1]
void flip(int* arr, int k) {
    int start = 0;
    int end = k - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    // Each target element needs at most 2 flips. Max possible flips = 2 * arrSize.
    int* result = (int*)malloc(2 * arrSize * sizeof(int));
    int count = 0;
    
    // Process from the largest value down to 1
    for (int value = arrSize; value > 0; value--) {
        // Find the index of the current target value
        int index = 0;
        while (arr[index] != value) {
            index++;
        }
        
        // If the value is already in its correct sorted position, skip it
        if (index == value - 1) {
            continue;
        }
        
        // Step 1: If it's not at the front, flip it to the front
        if (index != 0) {
            result[count++] = index + 1;
            flip(arr, index + 1);
        }
        
        // Step 2: Flip it to its final target position
        result[count++] = value;
        flip(arr, value);
    }
    
    *returnSize = count;
    return result;
}
