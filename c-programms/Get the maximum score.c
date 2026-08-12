#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSum(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i = 0, j = 0;
    
    // Use long long for intermediate sums to prevent overflow before modulo
    long long sum1 = 0;
    long long sum2 = 0;
    long long total_score = 0;
    
    long long MOD = 1000000007;
    
    // Step 1: Traverse both arrays together
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            sum1 += nums1[i];
            i++;
        } else if (nums1[i] > nums2[j]) {
            sum2 += nums2[j];
            j++;
        } else {
            // Intersection point found
            total_score += MAX(sum1, sum2) + nums1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    
    // Step 2: Collect remaining elements from nums1
    while (i < nums1Size) {
        sum1 += nums1[i];
        i++;
    }
    
    // Step 3: Collect remaining elements from nums2
    while (j < nums2Size) {
        sum2 += nums2[j];
        j++;
    }
    
    // Step 4: Add the final segment choice to the score
    total_score += MAX(sum1, sum2);
    
    // Return result bounded by modulo
    return (int)(total_score % MOD);
}
