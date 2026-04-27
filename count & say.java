class Solution {
    public String countAndSay(int n) {
        if (n <= 0) return "";
        String res = "1";
        
        // Iterate from 1 up to n
        for (int i = 1; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            int j = 0;
            
            // Process the current string to generate the next one
            while (j < res.length()) {
                char currentVal = res.charAt(j);
                int count = 0;
                
                // Count consecutive identical characters
                while (j < res.length() && res.charAt(j) == currentVal) {
                    count++;
                    j++;
                }
                
                // Append the count followed by the digit
                sb.append(count).append(currentVal);
            }
            res = sb.toString();
        }
        
        return res;
    }
}
