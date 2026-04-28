class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        
        // Start by assuming the first string is the entire prefix
        String prefix = strs[0];
        
        for (int i = 1; i < strs.length; i++) {
            // Shorten the prefix until it matches the start of the current string
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
                
                // If prefix becomes empty, there's no common prefix at all
                if (prefix.isEmpty()) return "";
            }
        }
        return prefix;
    }
}
