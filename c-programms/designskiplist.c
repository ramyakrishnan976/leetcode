#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEVEL 16  // Maximum height of the skiplist

typedef struct SkiplistNode {
    int val;
    struct SkiplistNode **next; // Array of pointers for different levels
} SkiplistNode;

typedef struct {
    SkiplistNode *head;
    int level; // Current max level of the list
} Skiplist;

// Helper to create a new node
SkiplistNode* createNode(int val, int level) {
    SkiplistNode *newNode = malloc(sizeof(SkiplistNode));
    newNode->val = val;
    newNode->next = malloc(sizeof(SkiplistNode*) * level);
    for (int i = 0; i < level; i++) newNode->next[i] = NULL;
    return newNode;
}

Skiplist* skiplistCreate() {
    Skiplist *obj = malloc(sizeof(Skiplist));
    obj->level = 1;
    obj->head = createNode(-1, MAX_LEVEL); // Dummy head
    return obj;
}

bool skiplistSearch(Skiplist* obj, int target) {
    SkiplistNode *curr = obj->head;
    for (int i = obj->level - 1; i >= 0; i--) {
        while (curr->next[i] && curr->next[i]->val < target) {
            curr = curr->next[i];
        }
    }
    curr = curr->next[0];
    return curr && curr->val == target;
}

void skiplistAdd(Skiplist* obj, int num) {
    SkiplistNode *update[MAX_LEVEL];
    SkiplistNode *curr = obj->head;

    // Find update positions at all levels
    for (int i = obj->level - 1; i >= 0; i--) {
        while (curr->next[i] && curr->next[i]->val < num) {
            curr = curr->next[i];
        }
        update[i] = curr;
    }

    // Determine random level for new node
    int lvl = 1;
    while (rand() % 2 == 0 && lvl < MAX_LEVEL) lvl++;
    
    if (lvl > obj->level) {
        for (int i = obj->level; i < lvl; i++) update[i] = obj->head;
        obj->level = lvl;
    }

    SkiplistNode *newNode = createNode(num, lvl);
    for (int i = 0; i < lvl; i++) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}

bool skiplistErase(Skiplist* obj, int num) {
    SkiplistNode *update[MAX_LEVEL];
    SkiplistNode *curr = obj->head;

    for (int i = obj->level - 1; i >= 0; i--) {
        while (curr->next[i] && curr->next[i]->val < num) {
            curr = curr->next[i];
        }
        update[i] = curr;
    }

    curr = curr->next[0];
    if (!curr || curr->val != num) return false;

    // Disconnect node from all levels
    for (int i = 0; i < obj->level; i++) {
        if (update[i]->next[i] != curr) break;
        update[i]->next[i] = curr->next[i];
    }

    free(curr->next);
    free(curr);

    // Update current max level of the list
    while (obj->level > 1 && obj->head->next[obj->level - 1] == NULL) {
        obj->level--;
    }
    return true;
}

void skiplistFree(Skiplist* obj) {
    SkiplistNode *curr = obj->head;
    while (curr) {
        SkiplistNode *next = curr->next[0];
        free(curr->next);
        free(curr);
        curr = next;
    }
    free(obj);
}
