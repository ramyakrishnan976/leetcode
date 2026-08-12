#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort by the profit/loss of sending a person to City B instead of City A
int compare(const void* a, const void* b) {
    int* costA = *(int**)a;
    int* costB = *(int**)b;
    
    int diffA = costA[1] - costA[0]; // Cost difference for person A
    int diffB = costB[1] - costB[0]; // Cost difference for person B
    
    return diffA - diffB;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    // Step 1: Sort the array based on the cost difference (CostB - CostA)
    qsort(costs, costsSize, sizeof(int*), compare);
    
    int total_cost = 0;
    int n = costsSize / 2;
    
    // Step 2: Send the first n people (with the best savings/least extra cost) to City B
    for (int i = 0; i < n; i++) {
        total_cost += costs[i][1];
    }
    
    // Step 3: Send the remaining n people to City A
    for (int i = n; i < costsSize; i++) {
        total_cost += costs[i][0];
    }
    
    return total_cost;
}
