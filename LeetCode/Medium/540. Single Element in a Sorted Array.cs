public class Solution {
    public int SingleNonDuplicate(int[] nums) {
        int n = nums.Length;

        int start = 0, end = n / 2, result = 0;
        while(start <= end)
        {
            int mid = (start + end) / 2;
            int idx = mid * 2;

            if(idx + 1 >= n || nums[idx] != nums[idx + 1])
            {
                result = nums[idx];
                end = mid - 1;
            }
            else start = mid + 1;
        }
        return result;
    }
}
