import java.util.*;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), s, 0);
        return result;
    }

    private void backtrack(List<List<String>> result, List<String> tempPath, String s, int start) {
        // Base case: if we've reached the end of the string, we found a valid partition
        if (start == s.length()) {
            result.add(new ArrayList<>(tempPath));
            return;
        }

        for (int i = start; i < s.length(); i++) {
            // If the current substring is a palindrome, recurse on the remainder
            if (isPalindrome(s, start, i)) {
                tempPath.add(s.substring(start, i + 1));
                backtrack(result, tempPath, s, i + 1);
                // Backtrack: remove the last substring to try a different split
                tempPath.remove(tempPath.size() - 1);
            }
        }
    }

    private boolean isPalindrome(String s, int low, int high) {
        while (low < high) {
            if (s.charAt(low++) != s.charAt(high--)) return false;
        }
        return true;
    }
}
