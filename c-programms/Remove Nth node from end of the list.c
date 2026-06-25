struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to seamlessly handle head removal edge cases
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // Move the fast pointer so there is a gap of n nodes between fast and slow
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches the end of the list
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow now points to the node BEFORE the target node
    slow->next = slow->next->next;
    
    return dummy.next;
}
