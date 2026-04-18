#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestRectangleArea(int* heights, int heightsSize) {
    // Stack to store indices
    int* stack = (int*)malloc((heightsSize + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {
        // Use 0 as a sentinel height at the end to flush the stack
        int currentHeight = (i == heightsSize) ? 0 : heights[i];

        // While current bar is shorter than the bar at stack top
        while (top != -1 && currentHeight < heights[stack[top]]) {
            int h = heights[stack[top--]];
            // Calculate width: if stack is empty, it covers everything from 0 to i
            int w = (top == -1) ? i : (i - stack[top] - 1);
            maxArea = MAX(maxArea, h * w);
        }
        stack[++top] = i;
    }

    free(stack);
    return maxArea;
}
