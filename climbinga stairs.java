class Solution {
    public int climbStairs(int n) {
        // Base cases
        if (n <= 2) {
            return n;
        }
        
        // Variables to store the ways to reach the previous two steps
        int first = 1;  // Ways to reach step 1
        int second = 2; // Ways to reach step 2
        
        // Iteratively calculate ways for subsequent steps up to n
        for (int i = 3; i <= n; i++) {
            int current = first + second;
            first = second;
            second = current;
        }
        
        return second;
    }
}
