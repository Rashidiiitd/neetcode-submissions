class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<int>& nums, int idx, int target, vector<int>& path)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }
        if( target <0 || idx >= nums.size())
        {
            return;
        }

        // take it
        path.push_back(nums[idx]); 
        dfs(nums, idx, target - nums[idx], path);
        path.pop_back();
        
        // dont take it.
        dfs(nums, idx + 1, target, path); 
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        dfs(nums, 0, target, path);
        
        return ans;
    }
};
