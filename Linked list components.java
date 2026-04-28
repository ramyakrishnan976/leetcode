import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        int components = 0;
        ListNode curr = head;
        boolean inComponent = false;

        while (curr != null) {
            if (set.contains(curr.val)) {
                // If we aren't already in a component, this is the start of a new one
                if (!inComponent) {
                    components++;
                    inComponent = true;
                }
            } else {
                // Current value is not in nums, so any previous component has ended
                inComponent = false;
            }
            curr = curr.next;
        }

        return components;
    }
}
