/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var swapPairs = function(head) {
    // 1. Initialize a dummy node to point to the head
    let dummy = new ListNode(0);
    dummy.next = head;
    let prev = dummy;

    // 2. Iterate while there are at least two nodes to swap
    while (prev.next !== null && prev.next.next !== null) {
        let first = prev.next;
        let second = prev.next.next;

        // 3. Perform the swap
        // Point first node to the third node
        first.next = second.next;
        // Point second node to the first node
        second.next = first;
        // Point the previous part of the list to the new pair head (second)
        prev.next = second;

        // 4. Move 'prev' pointer two nodes ahead for the next pair
        prev = first;
    }

    return dummy.next;
};
