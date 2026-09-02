#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

// Helper function to calculate (base^exp) % MOD using binary exponentiation
long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int numberOfWays(int n, int x, int y) {
    int maxK = (n < x) ? n : x; // k can at most be min(n, x)
    int maxLimit = (n > x) ? n : x;

    // 1. Allocate and Precompute Factorials and Inverse Factorials for nCk combinations
    long long* fact = (long long*)malloc((maxLimit + 1) * sizeof(long long));
    long long* invFact = (long long*)malloc((maxLimit + 1) * sizeof(long long));
    
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= maxLimit; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    
    // Fermat's Little Theorem for modular inverse of the maximum factorial
    invFact[maxLimit] = modPow(fact[maxLimit], MOD - 2);
    for (int i = maxLimit - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }

    // Helper macro function to get combinations nCk % MOD
    #define nCk(n_val, k_val) (((fact[n_val] * invFact[k_val]) % MOD * invFact[(n_val) - (k_val)]) % MOD)

    // 2. Precompute Stirling Numbers of the Second Kind up to S(n, maxK)
    // S[i][j] represents distributing i distinct elements into j identical non-empty sets
    long long** stirling = (long long**)malloc((n + 1) * sizeof(long long*));
    for (int i = 0; i <= n; i++) {
        stirling[i] = (long long*)calloc((maxK + 1), sizeof(long long));
    }
    
    stirling[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxK && j <= i; j++) {
            stirling[i][j] = (stirling[i - 1][j - 1] + (stirling[i - 1][j] * j)) % MOD;
        }
    }

    // 3. Accumulate total ways by scanning through all possible values of active stages 'k'
    long long totalWays = 0;
    
    for (int k = 1; k <= maxK; k++) {
        // Step A: Select k stages from x options
        long long currentWays = nCk(x, k);
        
        // Step B: Partition n performers into k groups
        currentWays = (currentWays * stirling[n][k]) % MOD;
        
        // Step C: Assign the k groups to the k specific stages (k!)
        currentWays = (currentWays * fact[k]) % MOD;
        
        // Step D: Assign scores to the k active bands (y^k)
        currentWays = (currentWays * modPow(y, k)) % MOD;
        
        // Add to total combinations
        totalWays = (totalWays + currentWays) % MOD;
    }

    // Clean up all dynamically allocated memory buffers
    for (int i = 0; i <= n; i++) {
        free(stirling[i]);
    }
    free(stirling);
    free(fact);
    free(invFact);

    return (int)totalWays;
}
