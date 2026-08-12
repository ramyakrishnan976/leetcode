#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxForm(char** strs, int strsSize, int m, int n) {
    // Step 1: Allocate and initialize the 2D DP matrix to 0
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)calloc(n + 1, sizeof(int));
    }

    // Step 2: Process each string one by one
    for (int s = 0; s < strsSize; s++) {
        int zeros = 0;
        int ones = 0;
        char* str = strs[s];
        
        // Count zeros and ones in the current binary string
        for (int k = 0; str[k] != '\0'; k++) {
            if (str[k] == '0') {
                zeros++;
            } else {
                ones++;
            }
        }

        // Step 3: Update DP table in reverse to prevent using the same string multiple times
        for (int i = m; i >= zeros; i--) {
            for (int j = n; j >= ones; j--) {
                dp[i][j] = MAX(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
    }

    int result = dp[m][n];

    // Step 4: Clean up dynamically allocated memory
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
