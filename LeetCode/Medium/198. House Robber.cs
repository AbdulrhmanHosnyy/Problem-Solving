public class Solution {
    public int Rob(int[] nums) {
        int n = nums.Length;
        int []arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = nums[0];
        for(int i = 1; i < n; i++)
        {
            arr[i + 1] = Math.Max(arr[i], arr[i - 1] + nums[i]);
        }
        return arr[n];
    }
}
