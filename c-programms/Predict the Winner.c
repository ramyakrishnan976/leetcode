#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool predictTheWinner(int* nums, int numsSize) {
    // Allocate memory for the 2D DP matrix
    int** dp = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int*)calloc(numsSize, sizeof(int));
    }

    // Step 1: Base case initialization (subarrays of length 1)
    for (int i = 0; i < numsSize; i++) {
        dp[i][i] = nums[i];
    }

    // Step 2: Build the DP table for subarrays of increasing lengths
    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i <= numsSize - len; i++) {
            int j = i + len - 1;
            
            // Choose between taking the left item or the right item
            int pick_left = nums[i] - dp[i + 1][j];
            int pick_right = nums[j] - dp[i][j - 1];
            
            dp[i][j] = MAX(pick_left, pick_right);
        }
    }

    // Step 3: Check if Player 1's relative score difference is non-negative
    bool player1_wins = dp[0][numsSize - 1] >= 0;

    // Step 4: Clean up allocated heap memory
    for (int i = 0; i < numsSize; i++) {
        free(dp[i]);
    }
    free(dp);

    return player1_wins;
}
