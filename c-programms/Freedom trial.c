#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int findRotateSteps(char* ring, char* key) {
    int ring_len = strlen(ring);
    int key_len = strlen(key);

    // Dynamically allocate DP table for key_len + 1 rows and ring_len columns
    int** dp = (int**)malloc((key_len + 1) * sizeof(int*));
    for (int i = 0; i <= key_len; i++) {
        dp[i] = (int*)calloc(ring_len, sizeof(int));
    }

    // Process bottom-up from the last character of the key back to the first
    for (int i = key_len - 1; i >= 0; i--) {
        for (int j = 0; j < ring_len; j++) {
            int min_steps = 1e9;

            // Try rotating to every index k on the ring that matches the target key character
            for (int k = 0; k < ring_len; k++) {
                if (ring[k] == key[i]) {
                    // Compute minimum distance (clockwise vs counter-clockwise)
                    int diff = abs(j - k);
                    int steps_to_align = MIN(diff, ring_len - diff);

                    // Total = rotation steps + 1 (button press) + remaining key steps
                    int total_steps = steps_to_align + 1 + dp[i + 1][k];
                    min_steps = MIN(min_steps, total_steps);
                }
            }
            dp[i][j] = min_steps;
        }
    }

    int final_result = dp[0][0];

    // Clean up allocated memory blocks
    for (int i = 0; i <= key_len; i++) {
        free(dp[i]);
    }
    free(dp);

    return final_result;
}
