class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        result = 0
        
        # Step 2 & 3: Linearly scan and XOR all elements
        for num in nums:
            result ^= num
            
        return result
