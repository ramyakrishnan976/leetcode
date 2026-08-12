#include <stdio.h>
#include <math.h>

int integerBreak(int n) {
    // Base edge cases forced by the k >= 2 constraint
    if (n == 2) return 1; // 1 * 1 = 1
    if (n == 3) return 2; // 2 * 1 = 2

    int quotient = n / 3;
    int remainder = n % 3;

    if (remainder == 0) {
        // Case 1: Perfectly divisible by 3
        return (int)pow(3, quotient);
    } 
    else if (remainder == 1) {
        // Case 2: Remainder is 1, steal a 3 to make a 4 (2 * 2)
        return (int)pow(3, quotient - 1) * 4;
    } 
    else {
        // Case 3: Remainder is 2, multiply the 3s by 2
        return (int)pow(3, quotient) * 2;
    }
}
