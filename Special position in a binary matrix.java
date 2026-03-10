class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        // Step 1: Record how many 1s are in each row and column
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int special = 0;
        // Step 2: Check each 1 to see if its row and column sums are exactly 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowCount[i] == 1 && colCount[j] == 1) {
                    special++;
                }
            }
        }
        
        return special;
    }
}
