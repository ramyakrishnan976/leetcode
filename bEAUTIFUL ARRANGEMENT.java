class Solution {

    public int countArrangement(int n) {
        // Start tracking from index 1, with a bitmask of 0 (no numbers used yet)
        return backtrack(1, 0, n);
    }

    private int backtrack(int index, int mask, int n) {
        // Base case: If we successfully filled all positions from 1 to n
        if (index > n) {
            return 1;
        }

        int count = 0;

        // Try placing every number 'i' (from 1 to n) at the current position 'index'
        for (int i = 1; i <= n; i++) {
            // Check if the number 'i' has NOT been used yet
            if ((mask & (1 << i)) == 0) {
                // Verify the beautiful arrangement condition
                if (i % index == 0 || index % i == 0) {
                    // Include 'i' in the mask and recursively move to the next position
                    count += backtrack(index + 1, mask | (1 << i), n);
                }
            }
        }

        return count;
    }
}
