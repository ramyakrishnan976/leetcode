class Solution {
    public String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        
        // Pointers for the end of each string
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop as long as there are digits or a remaining carry
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a.charAt(i) - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b.charAt(j) - '0'; // Convert char to int
                j--;
            }

            // sum % 2 gives the binary bit (0 or 1)
            result.append(sum % 2);
            
            // sum / 2 gives the carry (1 if sum >= 2, else 0)
            carry = sum / 2;
        }

        // The bits were added in reverse order, so we reverse it back
        return result.reverse().toString();
    }
}
