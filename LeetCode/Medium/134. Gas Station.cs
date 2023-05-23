public class Solution {
    public int CanCompleteCircuit(int[] gas, int[] cost) {
        if (gas.Sum() < cost.Sum()) return -1;
        int ans = 0;
        int current = 0;
        for (int i = 0; i < gas.Length; i++)
        {
            current += gas[i] - cost[i];
            if (current < 0)
            {
                current = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
}
