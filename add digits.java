class Solution {
    public int addDigits(int num) {
        // If num is 0, the digital root is 0
        if (num == 0) {
            return 0;
        }
        
        // Mathematical digital root formula
        int remainder = num % 9;
        return (remainder == 0) ? 9 : remainder;
    }
}
