#include <stdio.h>

// Macro to find the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize <= 1) {
        return 0;
    }

    // State 1: Maximum profit if we do NOT own a stock today
    int free = 0; 
    
    // State 2: Maximum profit if we DO own a stock today
    // Initialized by buying the stock on Day 0
    int hold = -prices[0]; 

    for (int i = 1; i < pricesSize; i++) {
        // Capture yesterday's free state before it gets overwritten
        int prev_free = free;

        // Update the 'free' state: 
        // Max of remaining cash-free or selling our stock today (paying the fee)
        free = MAX(free, hold + prices[i] - fee);

        // Update the 'hold' state: 
        // Max of continuing to hold or buying a new stock today using yesterday's free cash
        hold = MAX(hold, prev_free - prices[i]);
    }

    // The maximum profit always terminates on a stock-free liquid state
    return free;
}
