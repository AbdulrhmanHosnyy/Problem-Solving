public class Solution {
    public bool CanJump(int[] nums) {
    int n = nums.Length;
    int tmp = n - 1;
    for(int i = n - 2; i >= 0; i--)
    {
        if(nums[i] + i >= tmp) tmp = i;
    }
    if(tmp == 0) return true;
    return false;
    }
}
