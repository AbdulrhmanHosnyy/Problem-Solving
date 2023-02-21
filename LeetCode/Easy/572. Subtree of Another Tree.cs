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
    public bool IsSubtree(TreeNode root, TreeNode subRoot) {
        if(subRoot is null) return true;
        if(root is null) return false;
        if(IsSameTree(root, subRoot)) return true;
        return (IsSubtree(root.left, subRoot) ||
                IsSubtree(root.right, subRoot));
        
    }
    public bool IsSameTree(TreeNode p, TreeNode q) {
        if(p is null && q is null) return true;
        if((p is null || q is null) || p.val != q.val) return false;
        return (IsSameTree(p.right, q.right) && IsSameTree(p.left, q.left));
    }
}
