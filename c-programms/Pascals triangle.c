#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned arrays must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Set the number of rows to return
    *returnSize = numRows;
    
    // Allocate memory for the row pointer array
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    // Allocate memory to track the number of columns in each row
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    for (int i = 0; i < numRows; i++) {
        // Row i has exactly (i + 1) elements
        (*returnColumnSizes)[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        
        // The first and last elements of every row are always 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        // Calculate the intermediate values based on the previous row
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}
