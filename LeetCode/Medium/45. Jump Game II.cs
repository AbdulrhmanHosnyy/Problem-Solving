public class Solution {
    public int Jump(int[] nums) {
        int answer = 0;
        int l = 0, r = 0;
        while(r < nums.Length - 1)
        {
            int farthest = 0;
            for(int i = l; i <= r; i++)
                farthest = Math.Max(farthest, nums[i] + i);
            l = r + 1;
            r = farthest;
            answer++;
        }
        return answer;
    }
}
