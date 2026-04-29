class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        // 1. Sort to ensure duplicates are adjacent
        Arrays.sort(nums); 
        backtrack(result, new ArrayList<>(), nums, 0);
        return result;
    }

    private void backtrack(List<List<Integer>> result, List<Integer> tempList, int[] nums, int start) {
        result.add(new ArrayList<>(tempList));
        
        for (int i = start; i < nums.length; i++) {
            // 2. Skip the element if it's a duplicate of the previous one 
            // and we are at the same choice level (i > start)
            if (i > start && nums[i] == nums[i - 1]) continue;
            
            tempList.add(nums[i]);
            backtrack(result, tempList, nums, i + 1);
            tempList.remove(tempList.size() - 1);
        }
    }
}
