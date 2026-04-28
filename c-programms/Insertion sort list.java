/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    // Dummy node to act as the head of the sorted list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    struct ListNode* curr = head;
    
    while (curr != NULL) {
        // Save the next node to process before we re-link curr
        struct ListNode* nextNode = curr->next;

        // Search for the position in the sorted list starting from the dummy
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        // Insert curr into the sorted list
        curr->next = prev->next;
        prev->next = curr;

        // Move to the next node of the original list
        curr = nextNode;
    }

    struct ListNode* sortedHead = dummy->next;
    free(dummy); // Clean up the dummy node
    return sortedHead;
}
