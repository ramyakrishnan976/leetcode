class Solution {
    public String shortestPalindrome(String s) {
        if (s == null || s.length() <= 1) {
            return s;
        }

        // Create a temporary string: s + '#' + reverse(s)
        String revS = new StringBuilder(s).reverse().toString();
        String temp = s + "#" + revS;

        // Compute the KMP lookup table (LPS array) for the temporary string
        int[] lps = computeLPS(temp);

        // The last value in the LPS array gives the length of the longest palindromic prefix
        int longestPalindromicPrefixLength = lps[temp.length() - 1];

        // Take the characters after the palindromic prefix from the reversed string
        String suffixToAugment = revS.substring(0, s.length() - longestPalindromicPrefixLength);

        return suffixToAugment + s;
    }

    // Helper method to compute the Longest Prefix Suffix (LPS) array
    private int[] computeLPS(String str) {
        int n = str.length();
        int[] lps = new int[n];
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        while (i < n) {
            if (str.charAt(i) == str.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Fallback using previous table entries
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
}
