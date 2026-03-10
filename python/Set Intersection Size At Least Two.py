class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        # Sort by end ascending, then by start descending
        intervals.sort(key=lambda x: (x[1], -x[0]))
        
        # Initialize with two "dummy" small values
        res = 0
        last1, last2 = -1, -1
        
        for start, end in intervals:
            # Case 3: Zero points covered
            if start > last2:
                res += 2
                last1 = end - 1
                last2 = end
            # Case 2: Only one point covered (last2)
            elif start > last1:
                res += 1
                # If last2 is the end, pick end-1 as the new point
                # Otherwise, pick end as the new point
                last1 = last2
                last2 = end
            # Case 1: Two or more points already covered (start <= last1)
            # Do nothing
                
        return res
