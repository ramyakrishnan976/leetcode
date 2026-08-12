#include <stdio.h>
#include <stdlib.h>

// Structure to pair nums2 elements with their original indices
typedef struct {
    int value;
    int index;
} Element;

// Comparison function for basic integer sorting (nums1)
int compareInt(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    return (valA > valB) - (valA < valB); // Avoids overflow issues
}

// Comparison function for our Element structure (nums2)
int compareElement(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;
    return (elemA->value > elemB->value) - (elemA->value < elemB->value);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* result = (int*)malloc(nums1Size * sizeof(int));
    
    // Step 1: Create an array of Elements to preserve nums2 indices
    Element* sorted_nums2 = (Element*)malloc(nums2Size * sizeof(Element));
    for (int i = 0; i < nums2Size; i++) {
        sorted_nums2[i].value = nums2[i];
        sorted_nums2[i].index = i;
    }
    
    // Step 2: Sort both tracking structures
    qsort(nums1, nums1Size, sizeof(int), compareInt);
    qsort(sorted_nums2, nums2Size, sizeof(Element), compareElement);
    
    // Two pointers for nums1 (smallest and largest available elements)
    int low = 0;
    int high = nums1Size - 1;
    
    // Step 3: Iterate through sorted nums2 from largest to smallest
    for (int i = nums2Size - 1; i >= 0; i--) {
        int target_val = sorted_nums2[i].value;
        int target_idx = sorted_nums2[i].index;
        
        // If our biggest element beats their biggest element, use it
        if (nums1[high] > target_val) {
            result[target_idx] = nums1[high];
            high--;
        } 
        // Otherwise, sacrifice our smallest element against their giant element
        else {
            result[target_idx] = nums1[low];
            low++;
        }
    }
    
    free(sorted_nums2);
    return result;
}
