/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    int result = 0;
    public int DiameterOfBinaryTree(TreeNode root) {
        dfs(root);
        return result;
    }
    public int dfs(TreeNode root)
    {
        if(root == null) return -1;
        int left = dfs(root.left);
        int right = dfs(root.right);
        result = Math.Max(result, 2 + left + right);
        return 1 + Math.Max(left, right);
    }
}
