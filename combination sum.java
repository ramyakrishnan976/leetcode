import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> results = new ArrayList<>();
        // Sorting helps in pruning the search tree early
        Arrays.sort(candidates);
        backtrack(candidates, target, 0, new ArrayList<>(), results);
        return results;
    }

    private void backtrack(int[] candidates, int target, int start, 
                           List<Integer> current, List<List<Integer>> results) {
        if (target == 0) {
            // Found a valid combination
            results.add(new ArrayList<>(current));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            // Optimization: If current number exceeds remaining target, 
            // all subsequent numbers (being larger) will also exceed it.
            if (candidates[i] > target) break;

            current.add(candidates[i]);
            // Stay at index 'i' to allow reusing the same number
            backtrack(candidates, target - candidates[i], i, current, results);
            // Undo choice for the next iteration (backtrack)
            current.remove(current.size() - 1);
        }
    }
}
