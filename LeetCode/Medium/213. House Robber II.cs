public class Solution {
    public int Rob(int[] nums) {
       int n = nums.Length;
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.Max(nums[0], nums[1]);
        }
        int[] dp1 = new int[n];
        dp1[0] = nums[0];
        dp1[1] = Math.Max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = Math.Max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        int[] dp2 = new int[n];
        dp2[1] = nums[1];
        dp2[2] = Math.Max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            dp2[i] = Math.Max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        return Math.Max(dp1[n - 2], dp2[n - 1]);
    }
}
