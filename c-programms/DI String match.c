#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* s, int* returnSize) {
    int n = strlen(s);
    
    // The permutation will contain exactly n + 1 elements
    *returnSize = n + 1;
    int* perm = (int*)malloc((*returnSize) * sizeof(int));
    
    int low = 0;
    int high = n;
    
    // Step 1: Place elements greedily based on the character constraints
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            perm[i] = low;
            low++;
        } else { // s[i] == 'D'
            perm[i] = high;
            high--;
        }
    }
    
    // Step 2: Place the final remaining element where low == high
    perm[n] = low;
    
    return perm;
}
