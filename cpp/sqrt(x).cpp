class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int low = 1, high = x, ans = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Use division to prevent overflow (mid * mid > x)
            if (mid <= x / mid) {
                ans = mid;      // Potential answer found
                low = mid + 1;  // Try to find a larger one
            } else {
                high = mid - 1; // Too large, search lower half
            }
        }
        return ans;
    }
};
