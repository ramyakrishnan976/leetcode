#include <stdlib.h>

#define MOD 1000000007

// Structure to track vertical sweep line events
typedef struct {
    int x;
    int type; // +1 for entering a rectangle, -1 for leaving
    int y1, y2;
} Event;

// Comparator for events (sort by X coordinate)
int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->x != e2->x) {
        return (e1->x > e2->x) - (e1->x < e2->x);
    }
    return e1->type - e2->type;
}

// Comparator for sorting unique integers
int compareInts(const void* a, const void* b) {
    int i1 = *(int*)a;
    int i2 = *(int*)b;
    return (i1 > i2) - (i1 < i2);
}

int rectangleArea(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    int numEvents = rectanglesSize * 2;
    Event* events = (Event*)malloc(numEvents * sizeof(Event));
    
    int* allY = (int*)malloc(numEvents * sizeof(int));
    int yCount = 0;
    
    // 1. Populate events and Y coordinates
    for (int i = 0; i < rectanglesSize; i++) {
        int x1 = rectangles[i][0];
        int y1 = rectangles[i][1];
        int x2 = rectangles[i][2];
        int y2 = rectangles[i][3];
        
        events[2 * i] = (Event){x1, 1, y1, y2};
        events[2 * i + 1] = (Event){x2, -1, y1, y2};
        
        allY[yCount++] = y1;
        allY[yCount++] = y2;
    }
    
    // 2. Sort events by X-coordinate
    qsort(events, numEvents, sizeof(Event), compareEvents);
    
    // 3. Coordinate compression on Y-coordinates
    qsort(allY, yCount, sizeof(int), compareInts);
    
    int uniqueYCount = 0;
    for (int i = 0; i < yCount; i++) {
        if (uniqueYCount == 0 || allY[i] != allY[uniqueYCount - 1]) {
            allY[uniqueYCount++] = allY[i];
        }
    }
    
    // count array keeps track of how many active rectangles cover the segment between allY[i] and allY[i+1]
    int* segmentCount = (int*)calloc(uniqueYCount, sizeof(int));
    
    long long totalArea = 0;
    int prevX = events[0].x;
    
    // 4. Sweep-line simulation
    for (int i = 0; i < numEvents; i++) {
        Event currEvent = events[i];
        int currX = currEvent.x;
        
        // Compute total active vertical length for the current X span
        long long activeYLength = 0;
        for (int j = 0; j < uniqueYCount - 1; j++) {
            if (segmentCount[j] > 0) {
                activeYLength += (allY[j + 1] - allY[j]);
            }
        }
        
        // Add covered area to total area
        long long width = currX - prevX;
        if (width > 0 && activeYLength > 0) {
            totalArea = (totalArea + (width * activeYLength)) % MOD;
        }
        
        // Find indices of current event's Y coordinates in the compressed array
        int y1_idx = -1, y2_idx = -1;
        for (int j = 0; j < uniqueYCount; j++) {
            if (allY[j] == currEvent.y1) y1_idx = j;
            if (allY[j] == currEvent.y2) y2_idx = j;
            if (y1_idx != -1 && y2_idx != -1) break;
        }
        
        // Update the active segment configurations
        for (int j = y1_idx; j < y2_idx; j++) {
            segmentCount[j] += currEvent.type;
        }
        
        prevX = currX;
    }
    
    free(events);
    free(allY);
    free(segmentCount);
    
    return (int)totalArea;
}
