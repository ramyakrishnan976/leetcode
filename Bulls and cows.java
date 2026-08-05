class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        int cows = 0;
        
        // Array to track the frequency balance of digits 0-9
        int[] digitCounts = new int[10];
        
        for (int i = 0; i < secret.length(); i++) {
            int sDigit = secret.charAt(i) - '0';
            int gDigit = guess.charAt(i) - '0';
            
            if (sDigit == gDigit) {
                // Perfect position match
                bulls++;
            } else {
                // If sDigit has been seen previously in guess, it's a cow
                if (digitCounts[sDigit] < 0) {
                    cows++;
                }
                // If gDigit has been seen previously in secret, it's a cow
                if (digitCounts[gDigit] > 0) {
                    cows++;
                }
                
                // Track availability: secret increments balance, guess decrements balance
                digitCounts[sDigit]++;
                digitCounts[gDigit]--;
            }
        }
        
        // Format output as "xAyB"
        return bulls + "A" + cows + "B";
    }
}
