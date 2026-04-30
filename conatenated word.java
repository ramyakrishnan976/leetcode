import java.util.*;

class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        List<String> result = new ArrayList<>();
        // Sort words by length: shorter words are candidates to form longer ones
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        
        Set<String> dictionary = new HashSet<>();
        
        for (String word : words) {
            if (canForm(word, dictionary)) {
                result.add(word);
            }
            // Add the word to dictionary after checking to ensure 
            // a word isn't "forming itself" (unless it's a concatenation)
            dictionary.add(word);
        }
        
        return result;
    }

    private boolean canForm(String word, Set<String> dict) {
        if (dict.isEmpty()) return false;
        int n = word.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true; // Base case: empty string

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If prefix [0,j] is valid AND suffix [j,i] exists in dict
                if (dp[j] && dict.contains(word.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
