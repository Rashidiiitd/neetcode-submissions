class Solution {
public:
    vector<vector<int>> ans;
    int mask = 0;

    void printUtility(vector<int>&path)
    {
        for(auto it : path)
        {
            cout<<it<<endl;
        }
    }
   
    void dfs(vector<int>& nums, vector<int>& path)
    {
        if(path.size() == nums.size())
        {
            // printUtility(path);
            ans.push_back(path);
            return;
        }

        for(int i = 0; i <nums.size(); i++)
        {
            if(mask&(1<<i))
            {
                continue;
            }
            path.push_back(nums[i]);
            mask |= (1<<i);
            dfs(nums, path);
            path.pop_back();
            mask &= ~(1<<i);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>path;
        dfs(nums,path);

        return ans;
    }
};

