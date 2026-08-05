class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        // If the total length doesn't match, s3 cannot be an interleaving
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        // dp[j] will represent if s3[0...i+j-1] can be formed by s1[0...i-1] and s2[0...j-1]
        boolean[] dp = new boolean[s2.length() + 1];

        // Base case: empty s1 and empty s2 can form empty s3
        dp[0] = true;

        // Initialize the first row (where s1 is empty, only using prefixes of s2)
        for (int j = 1; j <= s2.length(); j++) {
            dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
        }

        // Fill the rest of the DP table line by line
        for (int i = 1; i <= s1.length(); i++) {
            // Update the first element of the row (where s2 is empty)
            dp[0] = dp[0] && s1.charAt(i - 1) == s3.charAt(i - 1);

            for (int j = 1; j <= s2.length(); j++) {
                // Current character from s3 we are matching
                char currentS3 = s3.charAt(i + j - 1);

                // Check if currentS3 matches character from s1 OR character from s2
                boolean matchS1 = dp[j] && s1.charAt(i - 1) == currentS3;
                boolean matchS2 = dp[j - 1] && s2.charAt(j - 1) == currentS3;

                dp[j] = matchS1 || matchS2;
            }
        }

        return dp[s2.length()];
    }
}
