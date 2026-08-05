class Solution {
    public boolean isAnagram(String s, String t) {
        // If lengths don't match, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Frequency bucket array for 26 lowercase English letters
        int[] charCounts = new int[26];

        // Process both strings in a single pass
        for (int i = 0; i < s.length(); i++) {
            charCounts[s.charAt(i) - 'a']++;
            charCounts[t.charAt(i) - 'a']--;
        }

        // If any bucket is not zero, the strings are not anagrams
        for (int count : charCounts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}
