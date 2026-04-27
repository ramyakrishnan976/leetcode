class Solution {
    public int brokenCalc(int startValue, int target) {
        int operations = 0;
        
        // Work backwards from target to startValue
        while (target > startValue) {
            operations++;
            if (target % 2 == 1) {
                target++; // Reverse of subtraction
            } else {
                target /= 2; // Reverse of multiplication
            }
        }
        
        // If target is now less than startValue, we can only use addition 
        // (which is the reverse of subtraction) to bridge the gap.
        return operations + (startValue - target);
    }
}
