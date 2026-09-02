#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countPalindromicSubsequences(char* s) {
    int n = strlen(s);
    long long MOD = 1000000007;

    // next_occ[i][c] stores the next occurrence index of character c starting from index i
    // prev_occ[i][c] stores the previous occurrence index of character c up to index i
    int (*next_occ)[4] = malloc(n * sizeof(*next_occ));
    int (*prev_occ)[4] = malloc(n * sizeof(*prev_occ));

    int last_seen[4] = {-1, -1, -1, -1};
    for (int i = 0; i < n; i++) {
        last_seen[s[i] - 'a'] = i;
        memcpy(prev_occ[i], last_seen, 4 * sizeof(int));
    }

    for (int i = 0; i < 4; i++) last_seen[i] = -1;
    for (int i = n - 1; i >= 0; i--) {
        last_seen[s[i] - 'a'] = i;
        memcpy(next_occ[i], last_seen, 4 * sizeof(int));
    }

    // Allocate memory for the 2D DP matrix
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    // Fill the DP table by iterating over substring lengths
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            long long total = 0;

            // Iterate over the 4 possible boundary characters
            for (int c = 0; c < 4; c++) {
                int left = next_occ[i][c];
                int right = prev_occ[j][c];

                // If character 'c' does not exist in the substring s[i...j] or out of bounds
                if (left == -1 || left > j || right < i) {
                    continue;
                }

                if (left == right) {
                    // Character occurs exactly once -> Contributes exactly 1 palindrome ("c")
                    total = (total + 1) % MOD;
                } else {
                    // Character occurs at least twice -> Contributes 2 ("c", "cc") 
                    // plus everything enclosed inside them
                    total = (total + 2 + (left + 1 <= right - 1 ? dp[left + 1][right - 1] : 0)) % MOD;
                }
            }
            dp[i][j] = (int)total;
        }
    }

    int result = dp[0][n - 1];

    // Free all allocated memory blocks
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);
    free(next_occ);
    free(prev_occ);

    return result;
}
