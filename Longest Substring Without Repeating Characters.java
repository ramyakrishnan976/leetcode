import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        int start = 0;
        // Map to store character and its most recent index
        Map<Character, Integer> charMap = new HashMap<>();

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);

            // If character is in window, update start to remove duplicate
            if (charMap.containsKey(currentChar)) {
                start = Math.max(start, charMap.get(currentChar) + 1);
            }

            // Update/Put character's current index
            charMap.put(currentChar, end);
            // Calculate current window length and update max
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }
}
