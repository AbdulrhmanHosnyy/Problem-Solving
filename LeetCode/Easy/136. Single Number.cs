public class Solution {
    public int SingleNumber(int[] nums) {
        int res = 0;
        foreach(var num in nums)
            res = res ^ num;
        return res;
    }
}
