import java.math.BigInteger;

class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        if (n < 3) return false;

        // i represents the ending index of the first number
        for (int i = 0; i < n / 2; i++) {
            // Numbers cannot have leading zeros except for the single digit '0'
            if (num.charAt(0) == '0' && i > 0) break; 
            
            String s1 = num.substring(0, i + 1);
            BigInteger n1 = new BigInteger(s1);

            // j represents the ending index of the second number
            // The remaining string must be at least as long as the max length of n1 and n2
            for (int j = i + 1; Math.max(i + 1, j - i) <= n - j - 1; j++) {
                if (num.charAt(i + 1) == '0' && j > i + 1) break;

                String s2 = num.substring(i + 1, j + 1);
                BigInteger n2 = new BigInteger(s2);

                // Check if this choice of the first two numbers can form a valid sequence
                if (isValidSequence(n1, n2, j + 1, num)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isValidSequence(BigInteger n1, BigInteger n2, int startIndex, String num) {
        // If we successfully processed the entire string, it's valid
        if (startIndex == num.length()) return true;

        // Calculate what the next expected number should be
        BigInteger nextSum = n1.add(n2);
        String nextSumStr = nextSum.toString();

        // Check if the remaining part of the string starts with the expected sum
        if (!num.startsWith(nextSumStr, startIndex)) {
            return false;
        }

        // Recursively or iteratively move down the line shifting the numbers forward
        return isValidSequence(n2, nextSum, startIndex + nextSumStr.length(), num);
    }
}
