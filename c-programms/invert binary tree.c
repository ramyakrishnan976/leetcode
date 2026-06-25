/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    // Base case: if the tree is empty, return NULL
    if (root == NULL) {
        return NULL;
    }

    // Post-order traversal: invert left and right subtrees first
    struct TreeNode* leftInverted = invertTree(root->left);
    struct TreeNode* rightInverted = invertTree(root->right);

    // Swap the left and right children of the current node
    root->left = rightInverted;
    root->right = leftInverted;

    // Return the root of the inverted tree
    return root;
}
