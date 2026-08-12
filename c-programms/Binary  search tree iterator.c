#include <stdlib.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Structure for a Stack Node to store TreeNodes manually
typedef struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
} StackNode;

// Definition for the Iterator object container
typedef struct {
    StackNode* top;
} BSTIterator;

// Helper function to push a TreeNode onto our stack layout
void push(BSTIterator* obj, struct TreeNode* node) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->treeNode = node;
    newNode->next = obj->top;
    obj->top = newNode;
}

// Helper function to pop a TreeNode off our stack layout
struct TreeNode* pop(BSTIterator* obj) {
    if (obj->top == NULL) return NULL;
    StackNode* temp = obj->top;
    struct TreeNode* node = temp->treeNode;
    obj->top = temp->next;
    free(temp);
    return node;
}

// Helper function to traverse left down the tree and push nodes
void pushAllLeft(BSTIterator* obj, struct TreeNode* node) {
    while (node != NULL) {
        push(obj, node);
        node = node->left;
    }
}

// Constructor to initialize the Iterator object
BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = NULL;
    // Pre-populate the stack with the initial leftmost branch path
    pushAllLeft(obj, root);
    return obj;
}

// Returns the next smallest element value
int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = pop(obj);
    int result = node->val;
    
    // If the node has a right child, its left-most branch nodes are the next elements
    if (node->right != NULL) {
        pushAllLeft(obj, node->right);
    }
    
    return result;
}

// Returns true if there are remaining unvisited items left on the stack
bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != NULL;
}

// Destructor to safely free memory allocations
void bSTIteratorFree(BSTIterator* obj) {
    while (obj->top != NULL) {
        pop(obj);
    }
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 * bool param_2 = bSTIteratorHasNext(obj);
 * bSTIteratorFree(obj);
 */
