#include <stdlib.h>
#include <stdbool.h>

#define MOD 1000000007

typedef struct {
    long long* arr;
    int size;
    int capacity;
    long long mul;
    long long add;
} Fancy;

// Helper function to calculate power under modulo (Fermat's Little Theorem)
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Helper function to find the modular inverse using base^(MOD-2)
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

Fancy* fancyCreate() {
    Fancy* obj = (Fancy*)malloc(sizeof(Fancy));
    obj->capacity = 200005; // Maximum bounds for 10^5 operations
    obj->arr = (long long*)malloc(obj->capacity * sizeof(long long));
    obj->size = 0;
    obj->mul = 1;
    obj->add = 0;
    return obj;
}

void fancyAppend(Fancy* obj, int val) {
    // Reverse the current linear transformation: stored = (val - add) / mul
    long long transformed = (val - obj->add + MOD) % MOD;
    transformed = (transformed * modInverse(obj->mul)) % MOD;
    
    obj->arr[obj->size++] = transformed;
}

void fancyAddAll(Fancy* obj, int inc) {
    obj->add = (obj->add + inc) % MOD;
}

void fancyMultAll(Fancy* obj, int m) {
    obj->mul = (obj->mul * m) % MOD;
    obj->add = (obj->add * m) % MOD;
}

int fancyGetIndex(Fancy* obj, int idx) {
    if (idx >= obj->size) {
        return -1;
    }
    // Reapply the active linear transformation: actual = (stored * mul) + add
    long long actual_val = (obj->arr[idx] * obj->mul) % MOD;
    actual_val = (actual_val + obj->add) % MOD;
    return (int)actual_val;
}

void fancyFree(Fancy* obj) {
    if (obj) {
        free(obj->arr);
        free(obj);
    }
}
