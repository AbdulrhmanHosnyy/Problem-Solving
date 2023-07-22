public class Solution {
    public int FindNumberOfLIS(int[] nums) {
        if (nums == null || nums.Length == 0) {
            return 0;
        }   
    
        int n = nums.Length;
        int[] dp = new int[n];
        int[] count = new int[n];
        Array.Fill(dp, 1);
        Array.Fill(count, 1);
        
        int maxLength = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLength = Math.Max(maxLength, dp[i]);
        }
        
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                result += count[i];
            }
        }
        
        return result;
    }
}
