#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* optimalDivision(int* nums, int numsSize) {
    // Allocate memory for the output string. 
    // Given the constraints (numsSize <= 10, each number <= 1000), 
    // a maximum buffer size of 100 characters is more than enough.
    char* result = (char*)malloc(100 * sizeof(char));
    result[0] = '\0'; // Initialize as an empty string
    
    // Base case 1: Only one number, no division operations possible
    if (numsSize == 1) {
        sprintf(result, "%d", nums[0]);
        return result;
    }
    
    // Base case 2: Two numbers, adding parentheses would be redundant
    if (numsSize == 2) {
        sprintf(result, "%d/%d", nums[0], nums[1]);
        return result;
    }
    
    // General case: Wrap everything after the first slash inside a single parenthesis pair.
    // This moves nums[2], nums[3], ... up to the numerator, maximizing the fraction value.
    char buffer[15];
    sprintf(result, "%d/(", nums[0]);
    
    for (int i = 1; i < numsSize; i++) {
        sprintf(buffer, "%d", nums[i]);
        strcat(result, buffer);
        
        // Append slash for all elements except the last one
        if (i < numsSize - 1) {
            strcat(result, "/");
        }
    }
    strcat(result, ")");
    
    return result;
}
