class Solution {
public:
    vector<vector<int>> ans;
   
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& path)
    {
          ans.push_back(path);

        if( idx >= candidates.size())
        {
            return;
        }
        for(int i = idx; i < candidates.size(); i++)
        {

            if(i > idx && candidates[i] == candidates[i-1]) 
            {
                continue; 
            }

            path.push_back(candidates[i]);
            dfs(candidates, target, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int>path;
        sort(nums.begin(),nums.end());
        dfs(nums,0,0,path);

        return ans;
    }
};
