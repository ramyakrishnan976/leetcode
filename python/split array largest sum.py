class Solution:
    def splitArray(self, nums: List[int], k: int) -> int:
        # The range of possible answers
        low = max(nums)
        high = sum(nums)
        ans = high
        
        while low <= high:
            mid = (low + high) // 2
            
            # Check if it's possible to split with 'mid' as the limit
            if self.canSplit(nums, k, mid):
                ans = mid
                high = mid - 1 # Try to find a smaller maximum
            else:
                low = mid + 1  # Need a larger maximum to use fewer subarrays
        
        return ans

    def canSplit(self, nums: List[int], k: int, max_sum: int) -> bool:
        subarray_count = 1
        current_sum = 0
        
        for num in nums:
            if current_sum + num > max_sum:
                # Start a new subarray
                subarray_count += 1
                current_sum = num
                if subarray_count > k:
                    return False
            else:
                current_sum += num
                
        return True
