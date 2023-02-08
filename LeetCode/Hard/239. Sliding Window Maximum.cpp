class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
    for(int i = 0; i < k; i++)
    {
        s.insert(nums[i]);
    }
    vector<int> v;
    for(int i = k; i < nums.size(); i++)
    {
        auto it = s.end();
        it--;
        v.push_back(*it);
        auto it2 = s.find(nums[i - k]);
        s.erase(it2);
        s.insert(nums[i]);
    }
    auto it = s.end();
    it--;
    v.push_back(*it);
    return v;
    }
};
