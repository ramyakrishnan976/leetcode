#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort in ascending order
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    // Step 1: Sort the dishes from least satisfying to most satisfying
    qsort(satisfaction, satisfactionSize, sizeof(int), compare);
    
    int total_like_time = 0;
    int running_sum = 0;
    
    // Step 2: Traverse from right to left (largest elements first)
    for (int i = satisfactionSize - 1; i >= 0; i--) {
        // If adding this dish keeps the cumulative satisfaction positive, include it
        if (running_sum + satisfaction[i] > 0) {
            running_sum += satisfaction[i];
            total_like_time += running_sum;
        } else {
            // As soon as the sum turns negative, further elements will only decrease the score
            break;
        }
    }
    
    return total_like_time;
}
