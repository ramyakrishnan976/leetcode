#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Macro to find the minimum of two values
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // dp[j] will store the minimum delete sum for s1[0...i] and s2[0...j]
    int* dp = (int*)malloc((len2 + 1) * sizeof(int));

    // Base Case: When s1 is empty, we must delete all characters of s2
    dp[0] = 0;
    for (int j = 1; j <= len2; j++) {
        dp[j] = dp[j - 1] + (int)s2[j - 1];
    }

    // Process row by row for characters in s1
    for (int i = 1; i <= len1; i++) {
        // prev tracks the diagonal element dp[i-1][j-1] before it gets overwritten
        int prev = dp[0];
        
        // Base case for column 0: When s2 is empty, delete all characters of s1
        dp[0] += (int)s1[i - 1];

        for (int j = 1; j <= len2; j++) {
            // Backup the current dp[j] value because it will act as 'prev' (dp[i-1][j]) 
            // for the next column calculation in this loop iteration.
            int temp = dp[j];

            if (s1[i - 1] == s2[j - 1]) {
                // If characters match, no characters need to be deleted at this position
                dp[j] = prev;
            } else {
                // If characters do not match, take the minimum option between:
                // 1. Deleting s1[i-1] -> dp[j] + s1[i-1]
                // 2. Deleting s2[j-1] -> dp[j-1] + s2[j-1]
                int deleteS1 = dp[j] + (int)s1[i - 1];
                int deleteS2 = dp[j - 1] + (int)s2[j - 1];
                dp[j] = MIN(deleteS1, deleteS2);
            }
            
            // Move our temporary backup pointer into prev
            prev = temp;
        }
    }

    int result = dp[len2];
    free(dp); // Free dynamically allocated array to prevent memory leaks
    
    return result;
}
