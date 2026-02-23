import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) return null;
        
        // PriorityQueue stores nodes, ordered by their value
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);
        
        // Add the head of each non-empty list to the heap
        for (ListNode list : lists) {
            if (list != null) {
                pq.add(list);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        
        while (!pq.isEmpty()) {
            // Get the smallest node
            ListNode smallest = pq.poll();
            curr.next = smallest;
            curr = curr.next;
            
            // If the extracted node has a next node, add it to the heap
            if (smallest.next != null) {
                pq.add(smallest.next);
            }
        }
        
        return dummy.next;
    }
}
