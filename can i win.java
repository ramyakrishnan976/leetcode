import java.util.*;

class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        // Base cases
        if (desiredTotal <= 0) return true;
        
        // If the sum of all numbers is less than the total, no one can reach it
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;

        // Use a Map for memoization: Bitmask -> Result (Boolean)
        return solve(maxChoosableInteger, desiredTotal, 0, new HashMap<>());
    }

    private boolean solve(int max, int total, int state, Map<Integer, Boolean> memo) {
        if (memo.containsKey(state)) return memo.get(state);

        for (int i = 1; i <= max; i++) {
            int mask = 1 << i;
            
            // If this number hasn't been used yet
            if ((state & mask) == 0) {
                // Check if choosing 'i' wins immediately OR makes the opponent lose
                if (total <= i || !solve(max, total - i, state | mask, memo)) {
                    memo.put(state, true);
                    return true;
                }
            }
        }

        memo.put(state, false);
        return false;
    }
}
