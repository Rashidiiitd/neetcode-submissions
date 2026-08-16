class Solution {
public:
    vector<vector<int>> ans;
   
    void dfs(vector<int>& candidates, int target, int idx, vector<int>& path)
    {
        if(target == 0)
        {
            ans.push_back(path);
            return;
        }

        if(target < 0 || idx >= candidates.size())
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
            dfs(candidates, target - candidates[i], i + 1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> path;
        dfs(candidates, target, 0, path);
        
        return ans;
    }
};
