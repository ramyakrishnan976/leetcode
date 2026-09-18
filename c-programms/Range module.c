#include <stdbool.h>
#include <stdlib.h>

// Dynamic Segment Tree Node
typedef struct Node {
    int tracked;        // 1 if completely tracked, 0 if completely untracked, -1 if mixed
    int lazy;           // 1 to add, 0 to remove, -1 for no pending update
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} RangeModule;

// Helper to create a new node
Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->tracked = 0;
    node->lazy = -1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Push lazy tags down to children
void pushDown(Node* node) {
    if (node->lazy == -1) return;
    
    if (!node->left) node->left = createNode();
    if (!node->right) node->right = createNode();
    
    node->left->tracked = node->lazy;
    node->left->lazy = node->lazy;
    
    node->right->tracked = node->lazy;
    node->right->lazy = node->lazy;
    
    node->lazy = -1; // Clear lazy tag
}

// Update range helper function
void update(Node* node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        node->tracked = val;
        node->lazy = val;
        return;
    }
    
    pushDown(node);
    int mid = l + (r - l) / 2;
    
    if (ql <= mid) {
        if (!node->left) node->left = createNode();
        update(node->left, l, mid, ql, qr, val);
    }
    if (qr > mid) {
        if (!node->right) node->right = createNode();
        update(node->right, mid + 1, r, ql, qr, val);
    }
    
    // Mix status logic
    int left_status = node->left ? node->left->tracked : 0;
    int right_status = node->right ? node->right->tracked : 0;
    if (left_status == 1 && right_status == 1) {
        node->tracked = 1;
    } else if (left_status == 0 && right_status == 0) {
        node->tracked = 0;
    } else {
        node->tracked = -1;
    }
}

// Query range helper function
bool query(Node* node, int l, int r, int ql, int qr) {
    if (!node) return false;
    if (node->tracked == 1) return true;
    if (node->tracked == 0) return false;
    if (ql <= l && r <= qr) return node->tracked == 1;
    
    pushDown(node);
    int mid = l + (r - l) / 2;
    bool ans = true;
    
    if (ql <= mid) {
        ans = ans && query(node->left, l, mid, ql, qr);
    }
    if (qr > mid) {
        ans = ans && query(node->right, mid + 1, r, ql, qr);
    }
    return ans;
}

// API Functions Implementation
RangeModule* rangeModuleCreate() {
    RangeModule* obj = (RangeModule*)malloc(sizeof(RangeModule));
    obj->root = createNode();
    return obj;
}

void rangeModuleAddRange(RangeModule* obj, int left, int right) {
    // [left, right) maps to [left, right - 1] in point queries
    update(obj->root, 1, 1000000000, left, right - 1, 1);
}

bool rangeModuleQueryRange(RangeModule* obj, int left, int right) {
    return query(obj->root, 1, 1000000000, left, right - 1);
}

void rangeModuleRemoveRange(RangeModule* obj, int left, int right) {
    update(obj->root, 1, 1000000000, left, right - 1, 0);
}

// Memory cleanup helper
void freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

void rangeModuleFree(RangeModule* obj) {
    if (obj) {
        freeTree(obj->root);
        free(obj);
    }
}
