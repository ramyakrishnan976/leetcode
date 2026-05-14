// REMOVE OR COMMENT OUT THIS BLOCK:
// struct ListNode {
//     int val;
//     struct ListNode *next;
// };

// 1. Safe Length Calculation
static int getLength(struct ListNode *head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// 2. Safe Splitting
static struct ListNode* split(struct ListNode *head, int step) {
    if (!head) return NULL;
    
    for (int i = 1; head && i < step; i++) {
        head = head->next;
    }
    
    if (!head) return NULL;
    
    struct ListNode *remainder = head->next;
    head->next = NULL; 
    return remainder;
}

// 3. Safe Merging
static struct ListNode* merge(struct ListNode *l1, struct ListNode *l2, struct ListNode **tail) {
    struct ListNode dummy = {0, NULL};
    struct ListNode *curr = &dummy;
    
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    
    curr->next = l1 ? l1 : l2;
    
    while (curr->next) {
        curr = curr->next;
    }
    
    *tail = curr; 
    return dummy.next;
}

// 4. Main Sorting Controller
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;
    
    int length = getLength(head);
    struct ListNode dummy = {0, head};
    
    for (int step = 1; step < length; step *= 2) {
        struct ListNode *curr = dummy.next;
        struct ListNode *tail = &dummy;
        
        while (curr) {
            struct ListNode *l1 = curr;
            struct ListNode *l2 = split(l1, step);
            
            curr = split(l2, step); 
            
            struct ListNode *merged_tail = NULL;
            tail->next = merge(l1, l2, &merged_tail);
            tail = merged_tail;
        }
    }
    
    return dummy.next;
}
