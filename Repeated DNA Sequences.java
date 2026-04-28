import java.util.*;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> seen = new HashSet<>();
        Set<String> repeated = new HashSet<>();
        
        // Loop through the string, stopping 10 characters before the end
        for (int i = 0; i <= s.length() - 10; i++) {
            String sub = s.substring(i, i + 10);
            
            // If we've seen this 10-letter sequence before, add it to repeated
            if (!seen.add(sub)) {
                repeated.add(sub);
            }
        }
        
        return new ArrayList<>(repeated);
    }
}
