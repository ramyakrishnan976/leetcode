#include <stdlib.h>
#include <math.h>

// Helper to calculate Greatest Common Divisor
static int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Structure to track slope frequencies
typedef struct {
    int dx;
    int dy;
    int count;
} SlopeCount;

struct ListNode; // LeetCode background context anchor placeholder

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 2) {
        return pointsSize;
    }
    
    int global_max = 2;
    
    // Allocate space for slope frequencies relative to one anchor point
    SlopeCount* map = (SlopeCount*)malloc(pointsSize * sizeof(SlopeCount));
    
    for (int i = 0; i < pointsSize; i++) {
        int map_size = 0;
        int local_max = 0;
        
        for (int j = 0; j < pointsSize; j++) {
            if (i == j) continue;
            
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];
            
            // Normalize fraction using GCD
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            
            // Force sign consistency
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            
            // Search if this slope exists in our local map
            int found = 0;
            for (int k = 0; k < map_size; k++) {
                if (map[k].dx == dx && map[k].dy == dy) {
                    map[k].count++;
                    if (map[k].count > local_max) {
                        local_max = map[k].count;
                    }
                    found = 1;
                    break;
                }
            }
            
            // If slope is seen for the first time
            if (!found) {
                map[map_size].dx = dx;
                map[map_size].dy = dy;
                map[map_size].count = 1;
                if (1 > local_max) {
                    local_max = 1;
                }
                map_size++;
            }
        }
        
        // Add 1 to include the anchor point itself
        if (local_max + 1 > global_max) {
            global_max = local_max + 1;
        }
    }
    
    free(map);
    return global_max;
}
