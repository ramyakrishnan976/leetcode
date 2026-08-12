#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    // Array to store the first n super ugly numbers
    int* super_ugly = (int*)malloc(n * sizeof(int));
    super_ugly[0] = 1; // The first super ugly number is always 1

    // Indices pointers tracking positions within the super_ugly array for each prime
    int* pointers = (int*)calloc(primesSize, sizeof(int));
    
    // An array to store the next candidate values to avoid recomputing multiplications
    long long* next_candidates = (long long*)malloc(primesSize * sizeof(long long));
    for (int i = 0; i < primesSize; i++) {
        next_candidates[i] = (long long)primes[i];
    }

    // Generate super ugly numbers sequentially from index 1 to n-1
    for (int i = 1; i < n; i++) {
        long long min_val = LLONG_MAX;

        // Step 1: Find the minimum candidate among all prime tracks
        for (int j = 0; j < primesSize; j++) {
            if (next_candidates[j] < min_val) {
                min_val = next_candidates[j];
            }
        }

        // Store the valid minimum candidate as the next super ugly number
        super_ugly[i] = (int)min_val;

        // Step 2: Advance pointers that generated this minimum value to avoid duplicates
        for (int j = 0; j < primesSize; j++) {
            if (next_candidates[j] == min_val) {
                pointers[j]++;
                // Update the next candidate value for this specific prime factor track
                next_candidates[j] = (long long)super_ugly[pointers[j]] * primes[j];
            }
        }
    }

    int result = super_ugly[n - 1];

    // Free all dynamically allocated memory pools
    free(super_ugly);
    free(pointers);
    free(next_candidates);

    return result;
}
