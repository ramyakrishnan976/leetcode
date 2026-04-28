import java.util.*;

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums, new boolean[nums.length]);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempPath, int[] nums, boolean[] used) {
        // Base case: if path size matches input size, we found a permutation
        if (tempPath.size() == nums.length) {
            result.add(new ArrayList<>(tempPath));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue; // Skip if element is already in the path

            used[i] = true;
            tempPath.add(nums[i]);
            
            backtrack(result, tempPath, nums, used);
            
            // Backtrack: remove the last element and mark as unused
            used[i] = false;
            tempPath.remove(tempPath.size() - 1);
        }
    }
}
