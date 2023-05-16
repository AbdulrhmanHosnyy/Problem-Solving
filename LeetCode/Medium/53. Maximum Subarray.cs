public class Solution {
    public int MaxSubArray(int[] nums) {
        int Maxi = nums[0];
        int curSum = 0;
        foreach(var num in nums)
        {
            if(curSum < 0) curSum = 0;
            curSum += num;
            Maxi = Math.Max(Maxi, curSum);
        }
        return Maxi;
    }
}
