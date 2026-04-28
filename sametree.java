
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // 1. Both nodes are null: trees are identical at this position
        if (p == null && q == null) {
            return true;
        }
        
        // 2. One node is null or values differ: trees are different
        if (p == null || q == null || p.val != q.val) {
            return false;
        }
        
        // 3. Recursively check left and right subtrees
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
