class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Vector to store prime flags, initialized to true
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;

        // Loop up to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i starting from i*i as non-prime
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count remaining primes
        int primeCount = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) primeCount++;
        }

        return primeCount;
    }
};
