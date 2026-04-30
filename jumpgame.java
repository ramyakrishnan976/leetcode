class Solution {
    public boolean canJump(int[] nums) {
        int farthest = 0;
        
        for (int i = 0; i < nums.length; i++) {
            // If the current index is beyond the farthest we can reach, fail
            if (i > farthest) {
                return false;
            }
            
            // Update farthest reach: max of current farthest or (current index + jump)
            farthest = Math.max(farthest, i + nums[i]);
            
            // Optimization: If farthest already reaches or exceeds the last index
            if (farthest >= nums.length - 1) {
                return true;
            }
        }
        
        return true;
    }
}
