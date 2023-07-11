/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public IList<int> DistanceK(TreeNode root, TreeNode target, int k) {
        var adjDict = GetAdjacencyDictionary(root);
        var visited = new HashSet<int>();
        var queue = new Queue<int>();
        queue.Enqueue(target.val);
        visited.Add(target.val);
        var distance = 0;

        while (queue.Any() && distance != k)
        {
            distance += 1;
            var count = queue.Count;
            for (var i = 0; i < count; i++)
            {
                var curr = queue.Dequeue();
                foreach (var next in adjDict[curr])
                {
                    if (visited.Add(next))
                    {
                        queue.Enqueue(next);
                    }
                }
            }
        }

        return queue.ToList();
    }
    private Dictionary<int, List<int>> GetAdjacencyDictionary(TreeNode root)
    {
        var adjDict = new Dictionary<int, List<int>>();
        adjDict[root.val] = new();
        TraverseDfs(root.left, root);
        TraverseDfs(root.right, root);
        return adjDict;

        void TraverseDfs(TreeNode node, TreeNode parent)
        {
            if (node != null)
            {
                adjDict[node.val] = new();
                adjDict[node.val].Add(parent.val);
                adjDict[parent.val].Add(node.val);
                TraverseDfs(node.left, node);
                TraverseDfs(node.right, node);
            }
        }
    }
}
