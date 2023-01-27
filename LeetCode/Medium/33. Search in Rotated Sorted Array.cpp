class Solution {
public:
    int search(vector<int>& nums, int target) {
        int e1 = nums.size() - 1;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1]) 
            {
                e1 = i;
                break;
            }
        }
        int s2 = 0;
        if(e1 != nums.size() - 1) s2 = e1 + 1;
        int s1 = 0;
        while(s1 <= e1)
        {
            int mid = (s1 + e1) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e1 = mid - 1;
            else s1 = mid + 1;
        }
        int e2 = nums.size() - 1;
        while(s2 <= e2)
        {
            int mid = (s2 + e2) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) e2 = mid - 1;
            else s2 = mid + 1;
        }
        return -1;
    }
};
