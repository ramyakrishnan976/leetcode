import heapq
from collections import Counter

class Solution:
    def reorganizeString(self, s: str) -> str:
        res = []
        # Max-Heap using negative counts
        max_heap = [(-count, char) for char, count in Counter(s).items()]
        heapq.heapify(max_heap)
        
        # Check if the most frequent character exceeds the limit
        if max_heap and -max_heap[0][0] > (len(s) + 1) // 2:
            return ""
        
        prev_count, prev_char = 0, ""
        
        while max_heap:
            count, char = heapq.heappop(max_heap)
            res.append(char)
            
            # Put the previous character back if it still has remaining count
            if prev_count < 0:
                heapq.heappush(max_heap, (prev_count, prev_char))
            
            # Decrement frequency and set as 'prev'
            prev_count, prev_char = count + 1, char
            
        return "".join(res)
