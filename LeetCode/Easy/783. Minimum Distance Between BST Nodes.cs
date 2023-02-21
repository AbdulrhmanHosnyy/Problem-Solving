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
    int minDistance = Int32.MaxValue;
    TreeNode prev;
    public int MinDiffInBST(TreeNode root) {
        helper(root);
        return minDistance;
    }
    public void helper(TreeNode root)
    {
        if(root == null) return;
        helper(root.left);
        if(prev != null) minDistance = Math.Min(minDistance, root.val - prev.val);
        prev = root;
        helper(root.right);
    }
}
