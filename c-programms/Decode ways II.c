#include <stdio.h>
#include <string.h>

int numDecodings(char* s) {
    long long MOD = 1000000007;
    int n = strlen(s);
    
    if (n == 0) return 0;
    
    // dp[-1] base configuration state
    long long first = 1; 
    
    // dp[0] initialization based on the first character
    long long second;
    if (s[0] == '0') {
        return 0; // A leading zero cannot be decoded
    } else if (s[0] == '*') {
        second = 9; // '*' can represent digits 1 to 9
    } else {
        second = 1; // Any single digit from 1 to 9 has 1 valid decoding way
    }
    
    for (int i = 1; i < n; i++) {
        long long current = 0;
        
        // ----------------------------------------------------
        // CASE 1: Decode the current single character s[i]
        // ----------------------------------------------------
        if (s[i] == '*') {
            current = (current + 9 * second) % MOD;
        } else if (s[i] != '0') {
            current = (current + second) % MOD;
        }
        
        // ----------------------------------------------------
        // CASE 2: Decode the two-character sequence s[i-1]s[i]
        // ----------------------------------------------------
        if (s[i - 1] == '1') {
            if (s[i] == '*') {
                current = (current + 9 * first) % MOD; // "11" through "19" -> 9 variants
            } else {
                current = (current + first) % MOD;     // "10" through "19" -> 1 variant
            }
        } 
        else if (s[i - 1] == '2') {
            if (s[i] == '*') {
                current = (current + 6 * first) % MOD; // "21" through "26" -> 6 variants
            } else if (s[i] <= '6') {
                current = (current + first) % MOD;     // "20" through "26" -> 1 variant
            }
        } 
        else if (s[i - 1] == '*') {
            if (s[i] == '*') {
                // "**" can represent "11"-"19" (9 ways) + "21"-"26" (6 ways) = 15 combinations
                current = (current + 15 * first) % MOD;
            } else if (s[i] <= '6') {
                // "*X" where X <= 6 can be "1X" or "2X" -> 2 variants
                current = (current + 2 * first) % MOD;
            } else {
                // "*X" where X > 6 can only be "1X" -> 1 variant
                current = (current + first) % MOD;
            }
        }
        
        // Shift state tracking variables forward for the next iteration
        first = second;
        second = current;
    }
    
    return (int)second;
}
