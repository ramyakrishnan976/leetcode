class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        long sum = 0;
        long f = 0;

        // Calculate total sum S and initial rotation F(0)
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += (long) i * nums[i];
        }

        long maxVal = f;

        // Iteratively calculate F(k) using the relationship
        for (int i = 1; i < n; i++) {
            // F(i) = F(i-1) + Sum - n * lastElementOfPreviousRotation
            f = f + sum - (long) n * nums[n - i];
            maxVal = Math.max(maxVal, f);
        }

        return (int) maxVal;
    }
}
