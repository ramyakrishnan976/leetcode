/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        // Dummy nodes to start our two lists
        ListNode smallerHead = new ListNode(0);
        ListNode greaterHead = new ListNode(0);
        
        // Pointers to move through the two lists
        ListNode smaller = smallerHead;
        ListNode greater = greaterHead;
        
        while (head != null) {
            if (head.val < x) {
                smaller.next = head;
                smaller = smaller.next;
            } else {
                greater.next = head;
                greater = greater.next;
            }
            head = head.next;
        }
        
        // Prevent cycles: the last node of 'greater' might still point to a 'smaller' node
        greater.next = null;
        
        // Stitch the two lists together
        smaller.next = greaterHead.next;
        
        return smallerHead.next;
    }
}
