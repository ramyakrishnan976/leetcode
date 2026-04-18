void reorderList(struct ListNode* head) {
    if (!head || !head->next || !head->next->next) return;

    // 1. Find the middle of the list (Slow & Fast Pointers)
    struct ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half of the list
    struct ListNode *prev = NULL, *curr = slow->next, *next = NULL;
    slow->next = NULL; // Split the list into two halves
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // 3. Merge the two halves (Interleaving)
    struct ListNode *p1 = head, *p2 = prev;
    while (p2) {
        struct ListNode *tmp1 = p1->next;
        struct ListNode *tmp2 = p2->next;

        p1->next = p2;
        p2->next = tmp1;

        p1 = tmp1;
        p2 = tmp2;
    }
}
