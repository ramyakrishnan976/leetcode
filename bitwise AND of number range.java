class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;
        
        // Shift both numbers to the right until they match
        // This strips away the changing lower bits to find the common prefix
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }
        
        // Shift back to the left to restore the original positions of the prefix bits
        return left << shiftCount;
    }
}
