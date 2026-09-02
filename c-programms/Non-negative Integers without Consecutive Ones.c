#include <stdio.h>

int findIntegers(int n) {
    // Precompute Fibonacci numbers up to 32 bits
    // f[i] will store the number of valid binary strings of length i
    int f[32];
    f[0] = 1; // Base case for length 0 (empty string or tracking remainder)
    f[1] = 2; // Length 1: "0", "1"
    for (int i = 2; i < 32; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    int sum = 0;
    int prev_bit = 0;
    
    // Scan bits from most significant (bit 30 because n <= 10^9) down to 0
    for (int i = 30; i >= 0; i--) {
        // Check if the i-th bit is set to 1
        if ((n & (1 << i)) != 0) {
            // If the i-th bit is 1, we could branch off and pick '0' instead.
            // This leaves i open positions, which yields f[i] combinations.
            sum += f[i];
            
            // If the previous bit was also 1, we found consecutive ones ("11").
            // Any further branches would exceed or match invalid prefixes of 'n'.
            if (prev_bit == 1) {
                return sum;
            }
            prev_bit = 1;
        } else {
            prev_bit = 0;
        }
    }

    // Add 1 to include the number 'n' itself if it didn't have consecutive ones
    return sum + 1;
}
