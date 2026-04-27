import java.util.*;

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        // Use a Set for O(1) word lookups
        Set<String> wordSet = new HashSet<>(wordDict);
        // Memoization map: substring -> list of possible sentences
        Map<String, List<String>> memo = new HashMap<>();
        return backtrack(s, wordSet, memo);
    }

    private List<String> backtrack(String s, Set<String> wordSet, Map<String, List<String>> memo) {
        if (memo.containsKey(s)) return memo.get(s);
        
        List<String> result = new ArrayList<>();
        // Base case: if string is empty, return a list with an empty string to allow concatenation
        if (s.isEmpty()) {
            result.add("");
            return result;
        }

        // Try every possible prefix
        for (int i = 1; i <= s.length(); i++) {
            String word = s.substring(0, i);
            if (wordSet.contains(word)) {
                // Get all valid suffixes for the remaining string
                List<String> suffixes = backtrack(s.substring(i), wordSet, memo);
                for (String suffix : suffixes) {
                    result.add(word + (suffix.isEmpty() ? "" : " ") + suffix);
                }
            }
        }

        memo.put(s, result);
        return result;
    }
}
