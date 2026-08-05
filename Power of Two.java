class Solution {
    public boolean isPowerOfTwo(int n) {
        // A power of two must be strictly greater than 0
        // and have exactly one bit set to 1.
        return n > 0 && (n & (n - 1)) == 0;
    }
}
