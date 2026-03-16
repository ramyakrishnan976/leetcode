class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        int m = mat.length;
        int n = mat[0].length;

        // 1. Check if reshaping is possible
        if (m * n != r * c) {
            return mat;
        }

        int[][] result = new int[r][c];
        int count = 0;

        // 2. Map elements from original to new matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Determine the new row and column using the running count
                result[count / c][count % c] = mat[i][j];
                count++;
            }
        }

        return result;
    }
}
