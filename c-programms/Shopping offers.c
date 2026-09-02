#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATE (1 << 24) // 6 items * 4 bits each = 24 bits max state size

// Global or dynamically allocated memo table to store minimum cost for each state mask
int* memo;

// Encode the needs array into a single unique integer bitmask
int encodeState(int* needs, int n) {
    int mask = 0;
    for (int i = 0; i < n; i++) {
        mask |= (needs[i] << (i * 4));
    }
    return mask;
}

int findMinPrice(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* currentNeeds, int n) {
    int stateMask = encodeState(currentNeeds, n);
    
    // Return cached result if this configuration has already been computed
    if (memo[stateMask] != -1) {
        return memo[stateMask];
    }
    
    // Base Baseline Strategy: Buy all remaining items at regular individual retail prices
    int minCost = 0;
    for (int i = 0; i < n; i++) {
        minCost += currentNeeds[i] * price[i];
    }
    
    // Alternative Strategy: Try to safely apply each special offer package deal
    for (int i = 0; i < specialSize; i++) {
        int* offer = special[i];
        int nextNeeds[6];
        int isValidOffer = 1;
        
        // Verify if applying the offer exceeds our rigid demand layout rules
        for (int j = 0; j < n; j++) {
            nextNeeds[j] = currentNeeds[j] - offer[j];
            if (nextNeeds[j] < 0) {
                isValidOffer = 0; // Over-buying is completely restricted
                break;
            }
        }
        
        // If the bundle is legal, recursively process the remaining requirements
        if (isValidOffer) {
            int offerPrice = offer[n]; // The last element holds the cost of this bundle
            int totalCostWithOffer = offerPrice + findMinPrice(price, priceSize, special, specialSize, specialColSize, nextNeeds, n);
            if (totalCostWithOffer < minCost) {
                minCost = totalCostWithOffer;
            }
        }
    }
    
    // Cache the minimum price discovered for this combination
    return memo[stateMask] = minCost;
}

int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize) {
    int n = priceSize;
    
    // Allocate memory for the memo table dynamically to avoid large stack frame allocations
    memo = (int*)malloc(MAX_STATE * sizeof(int));
    // Initialize the memo array values to -1 indicating uncomputed paths
    memset(memo, -1, MAX_STATE * sizeof(int));
    
    int result = findMinPrice(price, priceSize, special, specialSize, specialColSize, needs, n);
    
    // Free memory to completely eliminate leaks
    free(memo);
    
    return result;
}
