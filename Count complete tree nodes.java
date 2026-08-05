/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // If left height equals right height, it is a perfect binary tree
        if (leftHeight == rightHeight) {
            // formula: (1 << height) - 1
            return (1 << leftHeight) - 1;
        }

        // If it's not perfect, recurse on left and right subtrees and add 1 for root
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    // Helper method to find the height by going down the leftmost path
    private int getLeftHeight(TreeNode node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.left;
        }
        return height;
    }

    // Helper method to find the height by going down the rightmost path
    private int getRightHeight(TreeNode node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.right;
        }
        return height;
    }
}
