class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        
        for digit in num:
            # While we can still remove digits and the current digit 
            # is smaller than the last one added, remove the larger digit
            while k > 0 and stack and stack[-1] > digit:
                stack.pop()
                k -= 1
            stack.append(digit)
        
        # If k > 0, remove the remaining digits from the end
        final_stack = stack[:-k] if k > 0 else stack
        
        # Convert to string and remove leading zeros
        result = "".join(final_stack).lstrip('0')
        
        return result if result else "0"
