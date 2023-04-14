class Solution {  
  public:
   vector<vector<int>>ans;
void dfs(vector<int>&nums,vector<int>subset,int i) {
    if (i == nums.size()) {
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    dfs(nums,subset,i+1);

    subset.pop_back();
    dfs(nums,subset,i+1);
}

vector<vector<int>>subsets(vector<int>&nums) {
    vector<int>subset;
    dfs(nums,subset,0);
    return ans;
}
};
