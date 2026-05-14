#include <stddef.h>

struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int hasCycle = 0;
    
    // Phase 1: Detect if a cycle exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            hasCycle = 1;
            break;
        }
    }
    
    // If no cycle was detected, return NULL
    if (!hasCycle) {
        return NULL;
    }
    
    // Phase 2: Find the entry node of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}
