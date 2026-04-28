class Solution {
    public int strStr(String haystack, String needle) {
        int hLen = haystack.length();
        int nLen = needle.length();

        // If needle is longer than haystack, it's impossible to find it
        if (nLen > hLen) return -1;

        // Slide the window across the haystack
        // We stop at (hLen - nLen) because the window can't go past the end
        for (int i = 0; i <= hLen - nLen; i++) {
            
            // Check the current window of size nLen
            // substring(start, end) is the window
            if (haystack.substring(i, i + nLen).equals(needle)) {
                return i; // Found the first occurrence
            }
        }

        return -1; // Never found
    }
}
