#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Helper function to handle recursive postorder tracking
void postorderHelper(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    
    // 1. Traverse Left Subtree
    postorderHelper(root->left, arr, index);
    
    // 2. Traverse Right Subtree
    postorderHelper(root->right, arr, index);
    
    // 3. Process Root Node
    arr[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    // Constraints state max nodes = 100
    int* result = (int*)malloc(100 * sizeof(int));
    int index = 0;
    
    postorderHelper(root, result, &index);
    
    // Set the return size for the testing environment
    *returnSize = index;
    return result;
}
