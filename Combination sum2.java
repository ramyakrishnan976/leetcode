import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> results = new ArrayList<>();
        // Pruning: the smallest possible sum of k numbers is 1+2+...+k
        // The largest possible sum of k numbers is (10-k)+...+9
        if (n < (k * (k + 1)) / 2 || n > (k * (19 - k)) / 2) {
            return results;
        }
        
        backtrack(results, new ArrayList<>(), k, n, 1);
        return results;
    }

    private void backtrack(List<List<Integer>> results, List<Integer> currentCombination, int k, int targetSum, int startNum) {
        // Base case: if the combination has the required size
        if (currentCombination.size() == k) {
            // If the numbers sum up to n, add to results
            if (targetSum == 0) {
                results.add(new ArrayList<>(currentCombination));
            }
            return;
        }

        // Explore numbers from startNum up to 9
        for (int i = startNum; i <= 9; i++) {
            // Pruning: If the current number exceeds the remaining target sum, 
            // subsequent numbers will also be too large, so we can break early.
            if (i > targetSum) {
                break;
            }

            // Step 1: Choose the current number
            currentCombination.add(i);

            // Step 2: Recursively find the next numbers (start from i + 1 to avoid duplicates)
            backtrack(results, currentCombination, k, targetSum - i, i + 1);

            // Step 3: Undo choice (Backtrack)
            currentCombination.remove(currentCombination.size() - 1);
        }
    }
}
