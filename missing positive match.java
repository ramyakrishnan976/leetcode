class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            // While the current number is in range [1, n] 
            // and not in its correct position (nums[i] != nums[nums[i]-1])
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] with the element at its target index
                int targetIdx = nums[i] - 1;
                int temp = nums[i];
                nums[i] = nums[targetIdx];
                nums[targetIdx] = temp;
            }
        }

        // Second pass: find the first mismatch
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all positions are correct, the missing is n + 1
        return n + 1;
    }
}
