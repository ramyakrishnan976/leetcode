import java.util.*;

class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<>();
        if (s.length() < 4 || s.length() > 12) return res;
        backtrack(s, 0, new ArrayList<>(), res);
        return res;
    }

    private void backtrack(String s, int start, List<String> current, List<String> res) {
        // Base Case: If we have 4 segments
        if (current.size() == 4) {
            if (start == s.length()) {
                res.add(String.join(".", current));
            }
            return;
        }

        // Try lengths 1, 2, and 3 for the next segment
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) break;
            
            String segment = s.substring(start, start + len);
            
            // Validation: Range 0-255 and No Leading Zeros
            if ((segment.startsWith("0") && segment.length() > 1) || 
                (len == 3 && Integer.parseInt(segment) > 255)) {
                continue;
            }

            current.add(segment);               // Choose
            backtrack(s, start + len, current, res); // Explore
            current.remove(current.size() - 1); // Un-choose (Backtrack)
        }
    }
}
