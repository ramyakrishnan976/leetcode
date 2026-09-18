#include <stdbool.h>
#include <stdlib.h>

// Renamed to avoid conflicts with the system's built-in TreeNode
typedef struct CalendarNode {
    int start;
    int end;
    struct CalendarNode* left;
    struct CalendarNode* right;
} CalendarNode;

typedef struct {
    CalendarNode* root;
} MyCalendar;

// Helper to create a new tree node
CalendarNode* createNode(int start, int end) {
    CalendarNode* newNode = (CalendarNode*)malloc(sizeof(CalendarNode));
    newNode->start = start;
    newNode->end = end;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper to recursively insert and check for overlaps
bool insertNode(CalendarNode** root, int start, int end) {
    if (*root == NULL) {
        *root = createNode(start, end);
        return true;
    }
    
    // Overlap condition: start < root->end && end > root->start
    if (start < (*root)->end && end > (*root)->start) {
        return false; // Double booking detected
    }
    
    if (end <= (*root)->start) {
        return insertNode(&((*root)->left), start, end);
    } else {
        return insertNode(&((*root)->right), start, end);
    }
}

MyCalendar* myCalendarCreate() {
    MyCalendar* obj = (MyCalendar*)malloc(sizeof(MyCalendar));
    obj->root = NULL;
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int startTime, int endTime) {
    return insertNode(&(obj->root), startTime, endTime);
}

void freeTree(CalendarNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void myCalendarFree(MyCalendar* obj) {
    if (obj) {
        freeTree(obj->root);
        free(obj);
    }
}
