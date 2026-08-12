#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define OFFSET 100000

// Comparison function to sort elements by their absolute values
int compareAbs(const void* a, const void* b) {
    int valA = *(int*)a;
    int valB = *(int*)b;
    return abs(valA) - abs(valB);
}

bool canReorderDoubled(int* arr, int arrSize) {
    // A direct-address table to store frequencies of elements from -100000 to 100000
    int* count = (int*)calloc(200005, sizeof(int));
    
    // Step 1: Populate the frequency map
    for (int i = 0; i < arrSize; i++) {
        count[arr[i] + OFFSET]++;
    }
    
    // Step 2: Sort the array based on absolute values
    qsort(arr, arrSize, sizeof(int), compareAbs);
    
    // Step 3: Match each element with its double
    for (int i = 0; i < arrSize; i++) {
        int x = arr[i];
        
        // If this element has already been consumed by a previous match, skip it
        if (count[x + OFFSET] == 0) {
            continue;
        }
        
        int target = 2 * x;
        
        // Check if the double target is outside the valid range of the constraints
        if (target < -100000 || target > 100000) {
            free(count);
            return false;
        }
        
        // If the matching double element is not available, reordering is impossible
        if (count[target + OFFSET] <= 0) {
            free(count);
            return false;
        }
        
        // Consume one instance of the current element and one instance of its double
        count[x + OFFSET]--;
        count[target + OFFSET]--;
    }
    
    free(count);
    return true;
}
