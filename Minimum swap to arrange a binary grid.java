class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid.length;
        int[] trailingZeros = new int[n];
        
        // Step 1: Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros[i] = count;
        }
        
        int totalSwaps = 0;
        
        // Step 2: Greedy matching for each target row position
        for (int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int foundIdx = -1;
            
            // Find the first row at or below i that satisfies the requirement
            for (int j = i; j < n; j++) {
                if (trailingZeros[j] >= required) {
                    foundIdx = j;
                    break;
                }
            }
            
            if (foundIdx == -1) return -1; // Impossible to satisfy
            
            // Step 3: Swap it up to position i and count adjacent swaps
            for (int j = foundIdx; j > i; j--) {
                int temp = trailingZeros[j];
                trailingZeros[j] = trailingZeros[j - 1];
                trailingZeros[j - 1] = temp;
                totalSwaps++;
            }
        }
        
        return totalSwaps;
    }
}
