#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to perform the recursive traversal
void traverse(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    
    // Process Root
    arr[(*index)++] = root->val;
    
    // Process Left Subtree
    traverse(root->left, arr, index);
    
    // Process Right Subtree
    traverse(root->right, arr, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    // According to constraints, maximum nodes = 100
    int* result = (int*)malloc(100 * sizeof(int));
    int index = 0;
    
    traverse(root, result, &index);
    
    // Set the required return size parameter
    *returnSize = index;
    return result;
}
