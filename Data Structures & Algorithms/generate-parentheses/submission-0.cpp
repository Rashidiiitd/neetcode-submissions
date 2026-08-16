class Solution {
public:
    vector<string>ans;
    void dfs(int n,int open,int close,string &path)
    {
        if( path.size() == 2*n)
        {
            if(open == close)
            {
                ans.push_back(path);
               
            }

            return;
        }

        if(close>open)
        {
            return;
            // invalid 
        }

        // try open 
        // try close
        path.push_back('(');
        dfs(n,open+1,close,  path);
        path.pop_back();
        path.push_back(')');
        dfs(n,open,  close+1,path);
         path.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string path = "";
        dfs(n,0,0,path);

        return ans;

    }
};
