public class Solution {
    public int LongestSubsequence(int[] arr, int difference) {
        Dictionary<int, int> dp = new Dictionary<int, int>();
        int longestSubsequence = 1;
        foreach(int num in arr)
        {
            int check = num - difference;
            if(dp.ContainsKey(check)) 
            {
                dp[num] = dp[check] + 1;
            }
            else dp[num] = 1;
            longestSubsequence = Math.Max(longestSubsequence, dp[num]);
        }
        return longestSubsequence;
    }
}
