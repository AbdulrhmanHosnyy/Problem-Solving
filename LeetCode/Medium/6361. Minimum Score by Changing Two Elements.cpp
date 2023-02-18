class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 3)
            return nums[nums.size() -  2] - nums[1];
        else
        {
            return min(nums[nums.size() -  2] - nums[1], min(nums[nums.size() - 1] - nums[2],nums[nums.size() - 3] - nums[0]));
        }
    }
};
