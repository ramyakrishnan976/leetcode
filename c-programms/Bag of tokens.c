#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    // Step 1: Sort the tokens in ascending order
    qsort(tokens, tokensSize, sizeof(int), compare);
    
    int left = 0;
    int right = tokensSize - 1;
    int current_score = 0;
    int max_score = 0;
    
    // Step 2: Use two pointers to process tokens from both ends
    while (left <= right) {
        // Option 1: Play face-up with the smallest available token
        if (power >= tokens[left]) {
            power -= tokens[left];
            current_score++;
            left++;
            max_score = MAX(max_score, current_score);
        }
        // Option 2: Play face-down with the largest available token (if we have points to spend)
        else if (current_score > 0 && left < right) {
            power += tokens[right];
            current_score--;
            right--;
        }
        // If we can't play face-up or face-down, we stop
        else {
            break;
        }
    }
    
    return max_score;
}
