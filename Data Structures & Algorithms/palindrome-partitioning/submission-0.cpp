class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrom(string s,int start,int end)
    {
        int len = s.size()-1;

        // int start = 0;
        // int end  = len;
        while(start<end)
        {
            if(s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void helper(int index,string &s,vector<string>&currAns)
    {
        if(index ==  s.size())
        {
                ans.push_back(currAns);
                return;
        }

        for(int i = index;i<s.size();i++)
        {
            // {index .... i} tak ka partition is valid or not.
            if(isPalindrom(s,index,i))
            {
                currAns.push_back(s.substr(index, i - index + 1));

                 helper(i + 1, s, currAns);
                 currAns.pop_back();
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {

       ans.clear();
        vector<string>currAns;
        
        helper(0,s,currAns);
        return ans;

    }
};