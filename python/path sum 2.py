# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pathSum(self, root: TreeNode | None, targetSum: int) -> list[list[int]]:
        result = []
        
        def dfs(node: TreeNode | None, current_sum: int, current_path: list[int]):
            if not node:
                return
            
            # Step 2: Append current node value
            current_path.append(node.val)
            
            # Step 3: Check if it's a matching leaf node
            if not node.left and not node.right and node.val == current_sum:
                result.append(list(current_path)) # Snapshot copy
                
            # Step 4: Recursive traversal
            else:
                dfs(node.left, current_sum - node.val, current_path)
                dfs(node.right, current_sum - node.val, current_path)
                
            # Step 5: Backtrack to clean up path state
            current_path.pop()

        dfs(root, targetSum, [])
        return result
