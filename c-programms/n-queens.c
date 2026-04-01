#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    char ***results = malloc(sizeof(char**) * 1000); // Initial buffer for solutions
    *returnSize = 0;

    int *pos = malloc(sizeof(int) * n);
    int *cols = calloc(n, sizeof(int));
    int *diag1 = calloc(2 * n, sizeof(int));
    int *diag2 = calloc(2 * n, sizeof(int));

    void backtrack(int row) {
        if (row == n) {
            // Convert pos array to the required string format
            results[*returnSize] = malloc(sizeof(char*) * n);
            for (int i = 0; i < n; i++) {
                results[*returnSize][i] = malloc(n + 1);
                memset(results[*returnSize][i], '.', n);
                results[*returnSize][i][pos[i]] = 'Q';
                results[*returnSize][i][n] = '\0';
            }
            (*returnSize)++;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
                pos[row] = col;
                cols[col] = diag1[row - col + n] = diag2[row + col] = 1;
                
                backtrack(row + 1);
                
                // Backtrack
                cols[col] = diag1[row - col + n] = diag2[row + col] = 0;
            }
        }
    }

    backtrack(0);

    *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = n;

    // Cleanup local trackers
    free(pos); free(cols); free(diag1); free(diag2);
    return results;
}
