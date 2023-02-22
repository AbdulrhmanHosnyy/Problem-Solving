# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(node, maxi):
            if not node:
                return 0
            res = 1 if node.val >= maxi else 0
            maxi = max(maxi, node.val)
            res += dfs(node.left, maxi)
            res += dfs(node.right, maxi)
            return res
        return dfs(root, root.val)
