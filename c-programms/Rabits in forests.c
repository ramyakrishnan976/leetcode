#include <stdio.h>

int numRabbits(int* answers, int answersSize) {
    // Array to hold the frequency of each answer (0 to 999 based on constraints)
    int counts[1000] = {0};
    
    // Step 1: Count how many times each answer appears
    for (int i = 0; i < answersSize; i++) {
        counts[answers[i]]++;
    }
    
    int total_rabbits = 0;
    
    // Step 2: Calculate the minimum rabbits needed for each unique answer
    for (int x = 0; x < 1000; x++) {
        if (counts[x] > 0) {
            int group_size = x + 1;
            // Ceiling division trick to find how many groups of this size are needed
            int groups_needed = (counts[x] + x) / group_size;
            
            total_rabbits += groups_needed * group_size;
        }
    }
    
    return total_rabbits;
}
