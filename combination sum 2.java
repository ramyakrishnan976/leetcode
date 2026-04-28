import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        // Sort to handle duplicates and allow for early pruning
        Arrays.sort(candidates);
        backtrack(result, new ArrayList<>(), candidates, target, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempPath, int[] candidates, int remain, int start) {
        if (remain < 0) return; // Target exceeded
        if (remain == 0) {
            result.add(new ArrayList<>(tempPath));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            // Skip duplicates at the same recursive level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            tempPath.add(candidates[i]);
            // i + 1 ensures each number is used only once
            backtrack(result, tempPath, candidates, remain - candidates[i], i + 1);
            tempPath.remove(tempPath.size() - 1);
        }
    }
}
