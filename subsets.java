class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(result, new ArrayList<>(), nums, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempList, int[] nums, int start) {
        // Add the current subset to the result
        result.add(new ArrayList<>(tempList));
        
        for (int i = start; i < nums.length; i++) {
            tempList.add(nums[i]);            // Include element
            backtrack(result, tempList, nums, i + 1); // Move to next
            tempList.remove(tempList.size() - 1); // Undo choice (backtrack)
        }
    }
}
