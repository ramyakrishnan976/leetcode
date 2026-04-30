class Solution {
    public int integerReplacement(int n) {
        long num = n; // Use long to prevent overflow when n is Integer.MAX_VALUE
        int count = 0;

        while (num != 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                // Check if the last two bits are 11 (num % 4 == 3)
                // and ensure we don't apply the +1 rule to the number 3
                if (num == 3 || (num & 3) != 3) {
                    num--;
                } else {
                    num++;
                }
            }
            count++;
        }
        return count;
    }
}
