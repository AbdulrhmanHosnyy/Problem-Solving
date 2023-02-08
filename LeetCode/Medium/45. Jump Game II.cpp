class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, left = 0, right = 0;
        while(right < nums.size() - 1)
        {
            int newR = right + 1;
            for(int i = left; i <= right; i++)
            {
                newR = max(newR, i + nums[i]);
            }
            left = right + 1;
            right = newR;
            jumps++;
        }
        return jumps;
    }
};
