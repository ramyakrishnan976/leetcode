int findPeakElement(int* nums, int numsSize) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If the next element is greater, the peak lies on the right half
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } 
        // If the current element is greater or equal, the peak lies on the left half (including mid)
        else {
            right = mid;
        }
    }
    
    // When left == right, we have converged on a peak element
    return left;
}
