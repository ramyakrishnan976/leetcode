#include <stdio.h>
#include <stdlib.h>

// Helper macro to find the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int matrixScore(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    
    // Step 1: Ensure all rows start with 1. 
    // If a row starts with 0, flip that row entirely.
    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = 1 - grid[i][j]; // Toggle 0 to 1, and 1 to 0
            }
        }
    }
    
    // The first column is now guaranteed to have all 1s.
    // Each 1 in the first column contributes 2^(n-1) to the score.
    int total_score = m * (1 << (n - 1));
    
    // Step 2: Optimize subsequent columns greedly.
    for (int j = 1; j < n; j++) {
        int count_ones = 0;
        
        // Count how many 1s are currently in column j
        for (int i = 0; i < m; i++) {
            if (grid[i][j] == 1) {
                count_ones++;
            }
        }
        
        // We want the maximum number of 1s in this column.
        // If count_ones is less than half of m, flipping the column yields (m - count_ones) 1s.
        int optimal_ones = MAX(count_ones, m - count_ones);
        
        // Add the contribution of this column to the total score
        total_score += optimal_ones * (1 << (n - 1 - j));
    }
    
    return total_score;
}
