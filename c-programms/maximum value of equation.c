#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

long long findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k) {
    long long maxVal = -2e18; // Use a very small long long
    int* deque = (int*)malloc(pointsSize * sizeof(int));
    int head = 0, tail = 0;

    for (int j = 0; j < pointsSize; j++) {
        // 1. Remove indices outside the x-range: xj - xi > k
        while (tail > head && points[j][0] - points[deque[head]][0] > k) {
            head++;
        }

        // 2. If deque is not empty, the front index i gives the max (yi - xi)
        if (tail > head) {
            int i = deque[head];
            maxVal = MAX(maxVal, (long long)points[i][1] - points[i][0] + points[j][1] + points[j][0]);
        }

        // 3. Maintain monotonic deque (decreasing order of yi - xi)
        long long currentDiff = (long long)points[j][1] - points[j][0];
        while (tail > head) {
            int lastIdx = deque[tail - 1];
            if ((long long)points[lastIdx][1] - points[lastIdx][0] <= currentDiff) {
                tail--;
            } else {
                break;
            }
        }
        
        deque[tail++] = j;
    }

    free(deque);
    return maxVal;
}
