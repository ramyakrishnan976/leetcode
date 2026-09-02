#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Macro to find the minimum of two values
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int strangePrinter(char* s) {
    if (s == NULL || s[0] == '\0') {
        return 0;
    }

    int original_len = strlen(s);
    
    // Allocate a buffer to hold the compressed string
    char* compressed = (char*)malloc((original_len + 1) * sizeof(char));
    int n = 0;

    // Step 1: Compress consecutive identical characters (e.g., "aaabbb" -> "ab")
    for (int i = 0; i < original_len; i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            compressed[n++] = s[i];
        }
    }
    compressed[n] = '\0'; // Null-terminate the compressed string

    // Dynamic memory allocation for a 2D VLA-style equivalent array dp[n][n]
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
    }

    // Step 2: Loop through all possible substring lengths to fill the DP table
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // Base Case: A single character takes exactly 1 turn
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }

            // Initial assumption: Print the last character compressed[j] separately
            dp[i][j] = dp[i][j - 1] + 1;

            // Attempt to optimize the turn count if a matching character is found in the range
            for (int k = i; k < j; k++) {
                if (compressed[k] == compressed[j]) {
                    dp[i][j] = MIN(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                }
            }
        }
    }

    // Save the final result before cleaning up memory
    int result = dp[0][n - 1];

    // Step 3: Free all allocated memory blocks to prevent leaks
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(compressed);

    return result;
}
