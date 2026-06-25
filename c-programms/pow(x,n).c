double myPow(double x, int n) {
    // Use long long to prevent overflow when negating INT_MIN (-2147483648)
    long long N = n;
    
    // Handle negative exponent
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    
    double result = 1.0;
    double current_product = x;
    
    while (N > 0) {
        // If N is odd, multiply the current product into the result
        if (N % 2 == 1) {
            result *= current_product;
        }
        // Square the base and halve the exponent
        current_product *= current_product;
        N /= 2;
    }
    
    return result;
}
