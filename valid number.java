class Solution {
    public boolean isNumber(String s) {
        boolean seenDigit = false;
        boolean seenDot = false;
        boolean seenE = false;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (Character.isDigit(c)) {
                seenDigit = true;
            } else if (c == '+' || c == '-') {
                // Signs can only be at the start OR immediately after an 'e'
                if (i > 0 && s.charAt(i - 1) != 'e' && s.charAt(i - 1) != 'E') {
                    return false;
                }
            } else if (c == 'e' || c == 'E') {
                // 'e' can't appear twice and must follow a digit
                if (seenE || !seenDigit) return false;
                seenE = true;
                seenDigit = false; // Reset to ensure a digit follows the 'e'
            } else if (c == '.') {
                // Dot can't appear twice or after an 'e'
                if (seenDot || seenE) return false;
                seenDot = true;
            } else {
                return false;
            }
        }

        return seenDigit; 
    }
}
