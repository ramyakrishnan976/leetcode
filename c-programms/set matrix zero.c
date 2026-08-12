void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int col0 = 1; // Flag to track if the first column needs to be zeroed

    // Step 1: Scan the matrix and mark rows and columns using the first row/col
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) col0 = 0; // Check if first column has a zero
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0; // Mark row i
                matrix[0][j] = 0; // Mark column j
            }
        }
    }

    // Step 2: Iterate backwards to update cells using the markers
    // Moving backwards avoids overwriting the marker rows/cols before reading them
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0) {
            matrix[i][0] = 0; // Update first column cell if needed
        }
    }
}
