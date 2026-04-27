import java.util.*;

class Solution {
    public int findMinStep(String board, String hand) {
        // Sort hand to handle permutations easily and use as a key for memo
        int[] handCount = new int[26];
        for (char c : hand.toCharArray()) handCount[c - 'A']++;
        
        Map<String, Integer> memo = new HashMap<>();
        int result = dfs(board, handCount, memo);
        return result == Integer.MAX_VALUE ? -1 : result;
    }

    private int dfs(String board, int[] handCount, Map<String, Integer> memo) {
        board = removeGroups(board);
        if (board.isEmpty()) return 0;
        
        String state = board + Arrays.toString(handCount);
        if (memo.containsKey(state)) return memo.get(state);

        int minBalls = Integer.MAX_VALUE;

        // Try inserting a ball at every possible position
        for (int i = 0; i <= board.length(); i++) {
            for (int j = 0; j < 26; j++) {
                if (handCount[j] > 0) {
                    char color = (char) ('A' + j);
                    
                    // Optimization: Only insert if color matches current or next ball
                    // or if we are creating a group of 3.
                    boolean worthTrying = false;
                    if (i < board.length() && board.charAt(i) == color) worthTrying = true;
                    
                    if (worthTrying) {
                        handCount[j]--;
                        String nextBoard = board.substring(0, i) + color + board.substring(i);
                        int res = dfs(nextBoard, handCount, memo);
                        if (res != Integer.MAX_VALUE) {
                            minBalls = Math.min(minBalls, res + 1);
                        }
                        handCount[j]++; // Backtrack
                    }
                }
            }
        }

        memo.put(state, minBalls);
        return minBalls;
    }

    private String removeGroups(String board) {
        int i = 0;
        while (i < board.length()) {
            int j = i;
            while (j < board.length() && board.charAt(j) == board.charAt(i)) j++;
            if (j - i >= 3) {
                return removeGroups(board.substring(0, i) + board.substring(j));
            } else {
                i = j;
            }
        }
        return board;
    }
}
