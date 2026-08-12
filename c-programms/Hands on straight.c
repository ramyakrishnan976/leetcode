#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    // Step 1: Check if division into equal groups is possible
    if (handSize % groupSize != 0) {
        return false;
    }
    
    // Step 2: Sort the hand to process elements greedily from smallest to largest
    qsort(hand, handSize, sizeof(int), compare);
    
    // Keep track of visited/used cards
    bool* visited = (bool*)calloc(handSize, sizeof(bool));
    
    // Step 3: Iterate through the sorted cards to build groups
    for (int i = 0; i < handSize; i++) {
        // If this card is already part of another group, skip it
        if (visited[i]) {
            continue;
        }
        
        int current_card = hand[i];
        visited[i] = true;
        int cards_in_group = 1;
        
        // Look for the next groupSize - 1 consecutive cards
        int next_search_index = i + 1;
        while (cards_in_group < groupSize) {
            bool found_next = false;
            
            // Search for the exact consecutive card value needed
            for (int j = next_search_index; j < handSize; j++) {
                if (!visited[j] && hand[j] == current_card + 1) {
                    visited[j] = true;
                    current_card = hand[j]; // Update the target to look for the next value
                    cards_in_group++;
                    found_next = true;
                    
                    // Optimization: The next group search can start right after this matched card
                    if (j == next_search_index) {
                        next_search_index++;
                    }
                    break;
                }
                
                // Optimization: Since the array is sorted, if we exceed the target number,
                // it means the required card is missing entirely from the hand
                if (hand[j] > current_card + 1) {
                    break;
                }
            }
            
            // If we couldn't find the next consecutive card, grouping fails
            if (!found_next) {
                free(visited);
                return false;
            }
        }
    }
    
    free(visited);
    return true;
}
