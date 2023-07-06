public class Solution {
    public int MinSubArrayLen(int target, int[] nums) {
    int left = 0;
    int right = 0;
    int sum = 0;
    int minLength = int.MaxValue;

    while (right < nums.Length) {
        sum += nums[right];
        right++;
        while (sum >= target) {
            minLength = Math.Min(minLength, right - left);
            sum -= nums[left];
            left++;
        }
    }

    return minLength == int.MaxValue ? 0 : minLength;
    }
    
}
