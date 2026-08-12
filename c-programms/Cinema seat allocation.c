#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Comparison function to sort reserved seats by row number
int compareSeats(const void* a, const void* b) {
    int* seatA = *(int**)a;
    int* seatB = *(int**)b;
    if (seatA[0] != seatB[0]) {
        return (seatA[0] > seatB[0]) - (seatA[0] < seatB[0]);
    }
    return seatA[1] - seatB[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    // Step 1: Sort the reservations by row
    qsort(reservedSeats, reservedSeatsSize, sizeof(int*), compareSeats);
    
    int total_groups = 0;
    int unique_reserved_rows = 0;
    
    int i = 0;
    while (i < reservedSeatsSize) {
        int current_row = reservedSeats[i][0];
        int mask = 0;
        
        // Step 2: Accumulate all reservations for the current row into a bitmask
        while (i < reservedSeatsSize && reservedSeats[i][0] == current_row) {
            int seat = reservedSeats[i][1];
            // We only care about seats 2 to 9
            if (seat >= 2 && seat <= 9) {
                mask |= (1 << (seat - 2));
            }
            i++;
        }
        
        unique_reserved_rows++;
        
        // Step 3: Evaluate how many groups fit in this partially reserved row
        bool left_free = !(mask & 0x0F);   // Seats 2, 3, 4, 5
        bool right_free = !(mask & 0xF0);  // Seats 6, 7, 8, 9
        bool mid_free = !(mask & 0x3C);    // Seats 4, 5, 6, 7
        
        if (left_free && right_free) {
            total_groups += 2;
        } else if (left_free || right_free || mid_free) {
            total_groups += 1;
        }
    }
    
    // Step 4: Add 2 groups for each of the completely empty rows
    long long empty_rows = (long long)n - unique_reserved_rows;
    total_groups += empty_rows * 2;
    
    return total_groups;
}
