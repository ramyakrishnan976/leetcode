import java.util.Stack;

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();

        // Push all digits into stacks
        while (l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }

        ListNode head = null;
        int carry = 0;

        // Process stacks from bottom to top
        while (!s1.isEmpty() || !s2.isEmpty() || carry != 0) {
            int val1 = s1.isEmpty() ? 0 : s1.pop();
            int val2 = s2.isEmpty() ? 0 : s2.pop();
            
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            
            // Create new node and link it to the current head (building backwards)
            ListNode newNode = new ListNode(sum % 10);
            newNode.next = head;
            head = newNode;
        }

        return head;
    }
}
