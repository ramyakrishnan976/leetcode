#include <stdio.h>
#include <stdlib.h>

void swap(int* row, int* position, int i, int j) {
    // Swap the people in the row array
    int temp = row[i];
    row[i] = row[j];
    row[j] = temp;
    
    // Update their recorded positions in our lookup table
    position[row[i]] = i;
    position[row[j]] = j;
}

int minSwapsCouples(int* row, int rowSize) {
    // Table to look up the seat index of any person ID
    int position[100] = {0};
    for (int i = 0; i < rowSize; i++) {
        position[row[i]] = i;
    }
    
    int swaps = 0;
    
    // Traverse the row, two seats at a time
    for (int i = 0; i < rowSize; i += 2) {
        int first_person = row[i];
        // Using XOR to find the unique partner ID (e.g., 0^1 = 1, 1^1 = 0)
        int legal_partner = first_person ^ 1; 
        
        // If the person sitting next to first_person is not their legal partner
        if (row[i + 1] != legal_partner) {
            // Find where the legal partner is currently sitting
            int partner_current_seat = position[legal_partner];
            
            // Swap the person in the adjacent seat (i + 1) with the legal partner
            swap(row, position, i + 1, partner_current_seat);
            swaps++;
        }
    }
    
    return swaps;
}
