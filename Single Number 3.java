class Solution {
    public int[] singleNumber(int[] nums) {
        // Step 1: XOR all numbers to find the combined unique result (X ^ Y)
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        // Step 2: Extract the lowest set bit (rightmost 1) of the xorSum
        // This bit acts as a differentiator where X and Y have different bits
        int lowestSetBit = xorSum & -xorSum;

        // Step 3: Partition the elements into two groups based on the differentiator bit
        int firstUnique = 0;
        int secondUnique = 0;

        for (int num : nums) {
            if ((num & lowestSetBit) == 0) {
                // Group A: elements where the differentiator bit is 0
                firstUnique ^= num;
            } else {
                // Group B: elements where the differentiator bit is 1
                secondUnique ^= num;
            }
        }

        return new int[]{firstUnique, secondUnique};
    }
}
