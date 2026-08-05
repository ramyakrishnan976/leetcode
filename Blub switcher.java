class Solution {
    public int bulbSwitch(int n) {
        // The number of perfect squares up to n is exactly the floor of the square root of n
        return (int) Math.sqrt(n);
    }
}
