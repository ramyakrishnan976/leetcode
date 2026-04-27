class Solution {
    public int countTexts(String pressedKeys) {
        int n = pressedKeys.length();
        long mod = 1_000_000_007;
        
        // Precompute DP arrays up to max length (10^5)
        long[] dp3 = new long[n + 1];
        long[] dp4 = new long[n + 1];
        dp3[0] = dp4[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3 && i - j >= 0; j++) dp3[i] = (dp3[i] + dp3[i-j]) % mod;
            for (int j = 1; j <= 4 && i - j >= 0; j++) dp4[i] = (dp4[i] + dp4[i-j]) % mod;
        }

        long totalWays = 1;
        int i = 0;
        while (i < n) {
            int count = 1;
            while (i + 1 < n && pressedKeys.charAt(i) == pressedKeys.charAt(i + 1)) {
                count++;
                i++;
            }
            
            char digit = pressedKeys.charAt(i);
            if (digit == '7' || digit == '9') {
                totalWays = (totalWays * dp4[count]) % mod;
            } else {
                totalWays = (totalWays * dp3[count]) % mod;
            }
            i++;
        }
        
        return (int) totalWays;
    }
}
