/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
    // Base case: An empty tree has a depth of 0
    if (root == NULL) {
        return 0;
    }
    
    // Calculate the depth of both subtrees
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    // If left child is missing, path must go through the right child
    if (root->left == NULL) {
        return rightDepth + 1;
    }
    
    // If right child is missing, path must go through the left child
    if (root->right == NULL) {
        return leftDepth + 1;
    }
    
    // If both children exist, pick the shorter path
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}
