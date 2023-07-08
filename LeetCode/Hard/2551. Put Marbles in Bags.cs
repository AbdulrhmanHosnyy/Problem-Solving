public class Solution {
    public long PutMarbles(int[] weights, int k) {
        int n = weights.Length;
        if(n == 1 || k == n) return 0;
        long minSum = weights[0] + weights[n - 1];
        long maxSum = weights[0] + weights[n - 1];
        int[] helper = new int[n - 1];
        for(int i = 1; i < n; i++)
        {
            helper[i - 1] = weights[i - 1] + weights[i];
        }
        Array.Sort(helper);
        for(int i = 0; i < k - 1; i++) minSum += helper[i];
        for(int i = n - 2; i > n - 1 - k; i--) maxSum += helper[i];
        return maxSum - minSum;
    }
}
