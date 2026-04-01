#include <vector>
#include <algorithm>

class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Cyclic Sort (Place numbers in their correct 'home' index)
        for (int i = 0; i < n; ++i) {
            // We use a while loop because the swapped element might 
            // also need to be moved to its correct home.
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Identify the first index that doesn't hold its rightful owner
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If 1 to n are all present, the answer is n + 1
        return n + 1;
    }
};
