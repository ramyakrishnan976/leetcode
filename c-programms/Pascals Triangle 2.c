#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* row = (int*)malloc((*returnSize) * sizeof(int));
    
    // The first element is always 1
    row[0] = 1;
    
    // Compute the rest of the elements using the combination formula
    // We use a long long variable to prevent integer overflow during multiplication
    long long current = 1;
    
    for (int i = 1; i <= rowIndex; i++) {
        current = current * (rowIndex - i + 1) / i;
        row[i] = (int)current;
    }
    
    return row;
}
