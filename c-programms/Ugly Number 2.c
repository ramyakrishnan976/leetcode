#include <stdio.h>
#include <stdlib.h>

// Helper function to find the minimum of three numbers
int minOfThree(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int nthUglyNumber(int n) {
    // Array to store the first n ugly numbers
    int* ugly = (int*)malloc(n * sizeof(int));
    ugly[0] = 1; // The first ugly number is 1
    
    // Indices pointers for 2, 3, and 5 multiplication factors
    int p2 = 0, p3 = 0, p5 = 0;
    
    for (int i = 1; i < n; i++) {
        int next2 = ugly[p2] * 2;
        int next3 = ugly[p3] * 3;
        int next5 = ugly[p5] * 5;
        
        // The next ugly number is the smallest candidate
        int next_ugly = minOfThree(next2, next3, next5);
        ugly[i] = next_ugly;
        
        // Move the respective pointer(s) forward
        if (next_ugly == next2) p2++;
        if (next_ugly == next3) p3++;
        if (next_ugly == next5) p5++;
    }
    
    int result = ugly[n - 1];
    free(ugly); // Free dynamically allocated memory
    
    return result;
}
