class Solution {
    public int rob(int[] nums) {
        // Base case: only one house available
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        
        // Take the maximum of excluding the last house OR excluding the first house
        return Math.max(robLinear(nums, 0, nums.length - 2), 
                        robLinear(nums, 1, nums.length - 1));
    }
    
    // Helper method to solve the traditional linear House Robber problem
    private int robLinear(int[] nums, int start, int end) {
        int prevMax = 0;
        int currMax = 0;
        
        for (int i = start; i <= end; i++) {
            int temp = currMax;
            // Decide to either rob the current house + skip the previous, or skip the current house
            currMax = Math.max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        
        return currMax;
    }
}
