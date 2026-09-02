#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

// Renamed from maxPoints to maxScore to satisfy the driver compilation hook
int maxScore(int n, int k, int** stayScore, int stayScoreSize, int* stayScoreColSize, int** travelScore, int travelScoreSize, int* travelScoreColSize) {
    // Dynamically allocate memory for rolling DP arrays
    int* prev_dp = (int*)calloc(n, sizeof(int));
    int* dp = (int*)calloc(n, sizeof(int));

    // Simulate the tourist's choices day by day up to k rounds
    for (int d = 0; d < k; d++) {
        for (int dest = 0; dest < n; dest++) {
            // Case 1: Tourist chooses to stay in the city 'dest'
            int max_from_choices = prev_dp[dest] + stayScore[d][dest];

            // Case 2: Tourist chooses to travel from another city 'curr' to 'dest'
            for (int curr = 0; curr < n; curr++) {
                if (curr != dest) {
                    max_from_choices = MAX(max_from_choices, prev_dp[curr] + travelScore[curr][dest]);
                }
            }
            dp[dest] = max_from_choices;
        }
        // Roll over the current calculations to act as the baseline snapshot for the next day
        memcpy(prev_dp, dp, n * sizeof(int));
    }

    // Find the maximum score achieved among all possible ending cities
    int max_total_points = 0;
    for (int i = 0; i < n; i++) {
        max_total_points = MAX(max_total_points, dp[i]);
    }

    // Free dynamically allocated tracking arrays to prevent memory leaks
    free(prev_dp);
    free(dp);

    return max_total_points;
}
