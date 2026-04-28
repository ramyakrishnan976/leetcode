class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] isPal = new boolean[n][n];
        int[] cuts = new int[n];

        for (int j = 0; j < n; j++) {
            int min = j; // Maximum possible cuts (each char is a cut)
            for (int i = 0; i <= j; i++) {
                // If characters match AND (inner part is pal OR length <= 2)
                if (s.charAt(i) == s.charAt(j) && (j - i <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                    
                    // If s[0...j] is a palindrome, 0 cuts are needed
                    // Else, cuts = 1 (current cut) + min cuts for prefix before i
                    min = (i == 0) ? 0 : Math.min(min, cuts[i - 1] + 1);
                }
            }
            cuts[j] = min;
        }

        return cuts[n - 1];
    }
}
