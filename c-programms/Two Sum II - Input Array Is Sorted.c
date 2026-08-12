#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // Dynamically allocate memory for the 2-element results array
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int left = 0;
    int right = numbersSize - 1;
    
    while (left < right) {
        int current_sum = numbers[left] + numbers[right];
        
        if (current_sum == target) {
            // The problem requires 1-indexed output
            result[0] = left + 1;
            result[1] = right + 1;
            return result;
        } 
        else if (current_sum < target) {
            // Sum is too small, move the left pointer rightward to get a larger value
            left++;
        } 
        else {
            // Sum is too large, move the right pointer leftward to get a smaller value
            right--;
        }
    }
    
    return result; // Guaranteed to reach a solution per constraints
}
