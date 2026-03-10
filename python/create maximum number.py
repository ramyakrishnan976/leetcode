class Solution:
    def maxNumber(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        m, n = len(nums1), len(nums2)
        
        def get_max_subsequence(nums, length):
            stack = []
            drop = len(nums) - length
            for num in nums:
                while drop > 0 and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:length]

        def merge(s1, s2):
            # Lexicographical comparison handles the "lookahead" automatically
            return [max(s1, s2).pop(0) for _ in range(len(s1) + len(s2))]

        best = []
        # Find valid range for i (number of elements taken from nums1)
        for i in range(max(0, k - n), min(k, m) + 1):
            s1 = get_max_subsequence(nums1, i)
            s2 = get_max_subsequence(nums2, k - i)
            # Compare current merged result with the best found so far
            current_merge = merge(s1, s2)
            if current_merge > best:
                best = current_merge
        
        return best
