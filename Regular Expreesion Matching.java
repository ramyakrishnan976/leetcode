class Solution {
    Boolean[][] memo;

    public boolean isMatch(String s, String p) {
        memo = new Boolean[s.length() + 1][p.length() + 1];
        return dp(0, 0, s, p);
    }

    private boolean dp(int i, int j, String s, String p) {
        if (memo[i][j] != null) return memo[i][j];
        
        boolean result;
        // Base case: If we reached the end of the pattern
        if (j == p.length()) {
            result = (i == s.length());
        } else {
            // Check if the first characters match
            boolean firstMatch = (i < s.length() && 
                                 (p.charAt(j) == s.charAt(i) || p.charAt(j) == '.'));

            // Handle '*' wildcard
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                // Option 1: Skip the '*' sequence (zero occurrences)
                // Option 2: Use the '*' (if first chars match) and move forward in 's'
                result = dp(i, j + 2, s, p) || 
                         (firstMatch && dp(i + 1, j, s, p));
            } else {
                // Standard match
                result = firstMatch && dp(i + 1, j + 1, s, p);
            }
        }
        
        memo[i][j] = result;
        return result;
    }
}
