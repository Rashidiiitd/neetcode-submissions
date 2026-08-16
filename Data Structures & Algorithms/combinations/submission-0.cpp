class Solution {
public:
    vector<vector<int>> ans;

    void printUtility(vector<int>&path)
    {
        for(auto it : path)
        {
            cout<<it<<endl;
        }
    }
   
    void dfs(int n, int k, int idx, vector<int>& path)
    {
        if(path.size() == k)
        {
            // printUtility(path);
            ans.push_back(path);
            return;
        }

        for(int i = idx; i <=n; i++)
        {

            path.push_back(i);
            dfs(n,k, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>path;
        dfs(n,k,1,path);

        return ans;
    }
};