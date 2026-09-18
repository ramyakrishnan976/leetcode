#include <stdio.h>

int numTeams(int* rating, int ratingSize) {
    int totalTeams = 0;

    // Fix the middle element 'j'
    for (int j = 1; j < ratingSize - 1; j++) {
        int left_smaller = 0, left_larger = 0;
        int right_smaller = 0, right_larger = 0;

        // Count elements on the left of j
        for (int i = 0; i < j; i++) {
            if (rating[i] < rating[j]) {
                left_smaller++;
            } else if (rating[i] > rating[j]) {
                left_larger++;
            }
        }

        // Count elements on the right of j
        for (int k = j + 1; k < ratingSize; k++) {
            if (rating[k] < rating[j]) {
                right_smaller++;
            } else if (rating[k] > rating[j]) {
                right_larger++;
            }
        }

        // Add combinations for increasing and decreasing triplets
        totalTeams += (left_smaller * right_larger) + (left_larger * right_smaller);
    }

    return totalTeams;
}
