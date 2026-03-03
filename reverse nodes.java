class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        // Use a dummy node to simplify head changes
        ListNode dummy = new ListNode(0, head);
        ListNode groupPrev = dummy;

        while (true) {
            ListNode kth = getKth(groupPrev, k);
            if (kth == null) break; // Not enough nodes left to reverse
            
            ListNode groupNext = kth.next;
            
            // Standard Reversal Logic for k nodes
            ListNode prev = groupNext;
            ListNode curr = groupPrev.next;
            while (curr != groupNext) {
                ListNode tmp = curr.next;
                curr.next = prev;
                prev = curr;
                curr = tmp;
            }
            
            // Re-link the reversed group back into the main list
            ListNode tmp = groupPrev.next;
            groupPrev.next = kth;
            groupPrev = tmp;
        }
        return dummy.next;
    }

    // Helper method to find the k-th node from a starting point
    private ListNode getKth(ListNode curr, int k) {
        while (curr != null && k > 0) {
            curr = curr.next;
            k--;
        }
        return curr;
    }
}
