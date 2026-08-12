#include <stdio.h>
#include <stdlib.h>

// REMOVED: The custom 'struct TreeNode' block since it's already provided by the judge environment.

// Helper function to perform an in-order traversal and extract nodes into an array
void storeNodesInOrder(struct TreeNode* root, struct TreeNode** nodes, int* size) {
    if (root == NULL) {
        return;
    }
    
    storeNodesInOrder(root->left, nodes, size);
    nodes[(*size)++] = root;
    storeNodesInOrder(root->right, nodes, size);
}

// Helper function to recursively construct a balanced BST from a sorted array of nodes
struct TreeNode* buildBalancedTree(struct TreeNode** nodes, int start, int end) {
    if (start > end) {
        return NULL;
    }
    
    // Choose the middle element to keep subtrees balanced
    int mid = start + (end - start) / 2;
    struct TreeNode* root = nodes[mid];
    
    // Recursively construct the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);
    
    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    // According to constraints, the max number of nodes is 10,000
    struct TreeNode** nodes = (struct TreeNode**)malloc(10005 * sizeof(struct TreeNode*));
    int size = 0;
    
    // Step 1: Collect nodes in sorted order
    storeNodesInOrder(root, nodes, &size);
    
    // Step 2: Build a balanced tree from the sorted nodes list
    struct TreeNode* balancedRoot = buildBalancedTree(nodes, 0, size - 1);
    
    free(nodes);
    return balancedRoot;
}
