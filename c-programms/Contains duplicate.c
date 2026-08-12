#include <stdlib.h>
#include <stdbool.h>

// Comparison function needed for standard library qsort
int compare(const void* a, const void* b) {
    int num1 = *(const int*)a;
    int num2 = *(const int*)b;
    
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return false;
    }
    
    // Sort the array in ascending order
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Check if any adjacent elements are identical
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    
    return false;
}
