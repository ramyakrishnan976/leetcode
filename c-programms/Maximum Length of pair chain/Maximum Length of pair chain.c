#include <stdio.h>
#include <stdlib.h>

// Comparison function to sort pairs by their second element (right coordinate)
int comparePairs(const void* a, const void* b) {
    int* pairA = *(int**)a;
    int* pairB = *(int**)b;
    
    // Sort primarily by the right coordinate
    return pairA[1] - pairB[1];
}

int findLongestChain(int** pairs, int pairsSize, int* pairsColSize) {
    if (pairsSize == 0) return 0;

    // Step 1: Sort the pairs based on their end intervals greedily
    qsort(pairs, pairsSize, sizeof(int*), comparePairs);

    // Step 2: Track the end of the current chain and count elements
    int chainCount = 1;
    int currentEnd = pairs[0][1];

    for (int i = 1; i < pairsSize; i++) {
        // If the start of the next pair is greater than the end of the current chain
        if (pairs[i][0] > currentEnd) {
            chainCount++;
            currentEnd = pairs[i][1]; // Move the chain boundary forward
        }
    }

    return chainCount;
}
