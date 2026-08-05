import java.util.HashSet;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // A HashSet to keep track of elements in the current sliding window
        HashSet<Integer> window = new HashSet<>();
        
        for (int i = 0; i < nums.length; i++) {
            // If the current element is already in the window, we found a match
            if (window.contains(nums[i])) {
                return true;
            }
            
            // Add the current element to the window
            window.add(nums[i]);
            
            // If the window size exceeds k, remove the oldest element (leftmost)
            if (window.size() > k) {
                window.remove(nums[i - k]);
            }
        }
        
        return false;
    }
}
