#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int videoStitching(int** clips, int clipsSize, int* clipsColSize, int time) {
    // Array to store the maximum end time reachable from each start second
    // Constraints show start time and total time are capped at 100
    int max_reach[101] = {0};
    
    // Step 1: Populate the maximum reach for every starting position
    for (int i = 0; i < clipsSize; i++) {
        int start = clips[i][0];
        int end = clips[i][1];
        if (start <= 100) {
            max_reach[start] = MAX(max_reach[start], end);
        }
    }
    
    int clips_count = 0;
    int current_end = 0;
    int next_end = 0;
    
    // Step 2: Greedily step through each second up to time - 1
    for (int i = 0; i <= time; i++) {
        // If we have successfully covered the entire required time, exit early
        if (current_end >= time) {
            return clips_count;
        }
        
        // We cannot even reach the current second, meaning a gap exists
        if (i > next_end) {
            return -1;
        }
        
        // Update the furthest point we can reach using any available clip
        next_end = MAX(next_end, max_reach[i]);
        
        // If we reach the end of our current clip's range, we must activate a new clip
        if (i == current_end) {
            // If activating a new clip doesn't advance us, we are stuck
            if (next_end == current_end) {
                return -1;
            }
            clips_count++;
            current_end = next_end;
        }
    }
    
    return (current_end >= time) ? clips_count : -1;
}
