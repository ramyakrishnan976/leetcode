class Solution:
    def singleNumber(self, nums: list[int]) -> int:
        result = 0
        
        # Step 2: Loop through all 32 bit positions
        for i in range(32):
            bit_count = 0
            bit_mask = 1 << i
            
            # Step 3: Count how many numbers have this bit set
            for num in nums:
                if num & bit_mask:
                    bit_count += 1
            
            # Step 4: If the bit belongs to the single number, set it in result
            if bit_count % 3 != 0:
                # If we are looking at the 31st bit (sign bit), handle negative range
                if i == 31:
                    result -= bit_mask
                else:
                    result |= bit_mask
                    
        return result
