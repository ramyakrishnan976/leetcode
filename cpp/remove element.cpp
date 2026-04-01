#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int k = 0; // Pointer for the next position of a non-val element
        
        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is not the target value
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move it to the front
                k++; // Increment the count of valid elements
            }
        }
        
        return k;
    }
};
