#include <stdio.h>
#include <stdlib.h>

// Helper macro to find the maximum of two numbers
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Structure to return two values from our recursive calls
typedef struct {
    int rob;  // Max money if we choose to rob this node
    int skip; // Max money if we choose to skip this node
} RobResult;

// Helper function to process the tree bottom-up
RobResult helper(struct TreeNode* node) {
    RobResult result = {0, 0};
    if (node == NULL) {
        return result;
    }
    
    // Process left and right subtrees first (Post-order)
    RobResult left_res = helper(node->left);
    RobResult right_res = helper(node->right);
    
    // Case 1: Rob this node. We must skip both direct children.
    result.rob = node->val + left_res.skip + right_res.skip;
    
    // Case 2: Skip this node. We take the best possible path for each child independently.
    int max_left = MAX(left_res.rob, left_res.skip);
    int max_right = MAX(right_res.rob, right_res.skip);
    result.skip = max_left + max_right;
    
    return result;
}

int rob(struct TreeNode* root) {
    RobResult final_result = helper(root);
    
    // The answer is the maximum outcome of robbing or skipping the root node
    return MAX(final_result.rob, final_result.skip);
}
