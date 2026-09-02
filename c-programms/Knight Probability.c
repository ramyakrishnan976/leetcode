#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double knightProbability(int n, int k, int row, int column) {
    // Direction vectors representing the 8 possible L-shaped knight moves
    int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    // Dynamically allocate memory for two 2D grids (current move and next move states)
    double** dp = (double**)malloc(n * sizeof(double*));
    double** next_dp = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        dp[i] = (double*)calloc(n, sizeof(double));
        next_dp[i] = (double*)calloc(n, sizeof(double));
    }

    // Base Case: At move 0, the knight is at the starting square with 100% probability
    dp[row][column] = 1.0;

    // Simulate the knight's journey move-by-move up to k times
    for (int m = 0; m < k; m++) {
        // Clear out the next state tracking grid
        for (int i = 0; i < n; i++) {
            memset(next_dp[i], 0, n * sizeof(double));
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                // If there's a non-zero probability of being on this square
                if (dp[r][c] > 0.0) {
                    for (int i = 0; i < 8; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        // Verify if the landing coordinate is inside the chessboard bounds
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            next_dp[nr][nc] += dp[r][c] / 8.0;
                        }
                    }
                }
            }
        }

        // Swap the pointer references to roll over to the next step
        double** temp = dp;
        dp = next_dp;
        next_dp = temp;
    }

    // Aggregate the total remaining probability mass across the board layout
    double totalProbability = 0.0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            totalProbability += dp[r][c];
        }
    }

    // Free the dynamically allocated grid layers to prevent memory leaks
    for (int i = 0; i < n; i++) {
        free(dp[i]);
        free(next_dp[i]);
    }
    free(dp);
    free(next_dp);

    return totalProbability;
}
