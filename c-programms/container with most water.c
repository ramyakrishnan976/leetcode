#include <stdio.h>

// Helper function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int* height, int heightSize) {
    int max_water = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while (left < right) {
        // Calculate width and current area
        int width = right - left;
        int current_area = min(height[left], height[right]) * width;
        
        // Update max_water if current_area is larger
        if (current_area > max_water) {
            max_water = current_area;
        }
        
        // Move the pointer that points to the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return max_water;
}
