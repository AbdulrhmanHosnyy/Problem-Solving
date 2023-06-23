public class Solution {
    public int MinCostClimbingStairs(int[] cost) {
        int n = cost.Length;
        int [] helper = new int[n];
        helper[0] = cost[0];
        helper[1] = cost[1];
        for(int i = 2; i < n; i++)
        {
            helper[i] = cost[i] + Math.Min(helper[i - 1],
            helper[i - 2]);
        }
        return Math.Min(helper[n - 1], helper[n - 2]);
        //return Math.Min(helper(0, cost), helper(1, cost));
    }
    int helper(int n, int[] cost)
    {
        if(n >= cost.Length) return 0;
        return Math.Min(helper (n + 1, cost) + cost[n], 
        helper (n + 2, cost) + cost[n]);
    }
}
