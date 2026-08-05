class Solution {
    public int[] countBits(int n) {
        // Create an array of size n + 1
        int[] ans = new int[n + 1];
        
        // Base case: ans[0] is automatically initialized to 0
        
        // Fill the DP table using the bitwise relation
        for (int i = 1; i <= n; i++) {
            // i & (i - 1) removes the lowest set bit. 
            // We take its precomputed count and add 1 for the removed bit.
            ans[i] = ans[i & (i - 1)] + 1;
        }
        
        return ans;
    }
}
