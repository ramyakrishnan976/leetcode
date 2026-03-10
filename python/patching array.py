class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        patches = 0
        miss = 1  # The smallest number we cannot currently form
        i = 0
        
        while miss <= n:
            if i < len(nums) and nums[i] <= miss:
                # We can use the existing number to extend our range
                miss += nums[i]
                i += 1
            else:
                # We must patch 'miss' to cover the gap greedily
                miss += miss
                patches += 1
                
        return patches
