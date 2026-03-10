class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        
        # Move fast pointer by 2 and slow by 1
        while fast and fast.next:
            slow = slow.next          # moves 1 step
            fast = fast.next.next     # moves 2 steps
            
            # If they meet, there is a cycle
            if slow == fast:
                return True
        
        # If fast reaches the end, there is no cycle
        return False
