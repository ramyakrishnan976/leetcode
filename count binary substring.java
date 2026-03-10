class Solution {
    public int countBinarySubstrings(String s) {
        int curr = 1;
        int prev = 0;
        int result = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                curr++;
            } else {
                // When we hit a change, the number of valid substrings 
                // between the previous group and current group is min(prev, curr)
                result += Math.min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        // Final addition for the last two groups
        return result + Math.min(prev, curr);
    }
}
