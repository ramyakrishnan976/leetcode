class Solution:
    def maximumSwap(self, num: int) -> int:
        digits = list(str(num))
        # Record the last index of every digit 0-9
        last = {int(d): i for i, d in enumerate(digits)}
        
        # Scan each digit from left to right
        for i, d in enumerate(digits):
            # Check for any digit larger than the current one (starting from 9)
            for larger_digit in range(9, int(d), -1):
                # If a larger digit exists later in the string
                if last.get(larger_digit, -1) > i:
                    # Swap and return
                    idx = last[larger_digit]
                    digits[i], digits[idx] = digits[idx], digits[i]
                    return int("".join(digits))
        
        return num
