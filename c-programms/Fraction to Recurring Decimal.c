#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A simple hash node to track where each remainder was first seen in the result string
typedef struct {
    long long remainder;
    int index;
} RemainderMap;

// Helper function to find a remainder in our tracked list
int findRemainderIndex(RemainderMap* map, int mapSize, long long rem) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].remainder == rem) {
            return map[i].index;
        }
    }
    return -1;
}

char* fractionToDecimal(int numerator, int denominator) {
    // Allocate memory for the output string (guaranteed length < 10000)
    char* res = (char*)malloc(10005 * sizeof(char));
    int pos = 0;

    // Handle 0 numerator edge case
    if (numerator == 0) {
        strcpy(res, "0");
        return res;
    }

    // Determine the sign of the result
    if ((numerator < 0) ^ (denominator < 0)) {
        res[pos++] = '-';
    }

    // Convert to long long to prevent absolute value integer overflows (e.g. INT_MIN)
    long long num = llabs((long long)numerator);
    long long den = llabs((long long)denominator);

    // 1. Process Integral Part
    long long integral = num / den;
    pos += sprintf(&res[pos], "%lld", integral);

    long long rem = num % den;
    if (rem == 0) {
        res[pos] = '\0';
        return res;
    }

    // 2. Process Fractional Part
    res[pos++] = '.';
    
    // Create a local map to track remainders (constraints ensure total operations are small)
    RemainderMap map[10005];
    int mapSize = 0;

    while (rem != 0) {
        // Check if we have encountered this remainder before
        int remIdx = findRemainderIndex(map, mapSize, rem);
        if (remIdx != -1) {
            // Found a repeating cycle! Shift characters right to insert opening parenthesis '('
            int len = strlen(res);
            for (int i = len; i >= remIdx; i--) {
                res[i + 1] = res[i];
            }
            res[remIdx] = '(';
            pos++;
            
            // Append closing parenthesis ')'
            res[pos++] = ')';
            res[pos] = '\0';
            return res;
        }

        // Record the current remainder and its exact character position
        map[mapSize].remainder = rem;
        map[mapSize].index = pos;
        mapSize++;

        // Simulate long division step
        rem *= 10;
        res[pos++] = (rem / den) + '0';
        rem %= den;
    }

    res[pos] = '\0';
    return res;
}
