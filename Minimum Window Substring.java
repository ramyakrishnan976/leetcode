class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.length() < t.length()) return "";

        // Frequency map for characters in t
        int[] map = new int[128];
        for (char c : t.toCharArray()) {
            map[c]++;
        }

        int left = 0, right = 0;
        int minLen = Integer.MAX_VALUE;
        int start = 0;
        int count = t.length(); // Total characters needed to be "valid"

        while (right < s.length()) {
            // Expand the window
            char rChar = s.charAt(right);
            if (map[rChar] > 0) {
                count--;
            }
            map[rChar]--;
            right++;

            // When window is valid, try to contract it
            while (count == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                char lChar = s.charAt(left);
                map[lChar]++;
                // If the count goes above 0, it means we lost a required character
                if (map[lChar] > 0) {
                    count++;
                }
                left++;
            }
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
    }
}
