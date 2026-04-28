import java.util.*;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums); // Crucial: Sort to bring duplicates together
        backtrack(result, new ArrayList<>(), nums, new boolean[nums.length]);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempPath, int[] nums, boolean[] used) {
        if (tempPath.size() == nums.length) {
            result.add(new ArrayList<>(tempPath));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // Skip if used
            if (used[i]) continue;
            
            // Skip duplicates: 
            // If the current number is the same as the previous one, 
            // and the previous one was NOT used in the current recursion level, skip it.
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            used[i] = true;
            tempPath.add(nums[i]);
            
            backtrack(result, tempPath, nums, used);
            
            used[i] = false;
            tempPath.remove(tempPath.size() - 1);
        }
    }
}
