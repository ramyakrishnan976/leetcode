struct ListNode* oddEvenList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode* odd = head;           // Pointer for the odd chain
    struct ListNode* even = head->next;    // Pointer for the even chain
    struct ListNode* evenHead = even;      // Keep track of even head to connect later

    while (even && even->next) {
        odd->next = even->next;            // Connect odd to the next odd node
        odd = odd->next;                   // Move odd pointer
        
        even->next = odd->next;            // Connect even to the next even node
        even = even->next;                 // Move even pointer
    }

    odd->next = evenHead;                  // Attach even list to the end of odd list
    return head;
}
