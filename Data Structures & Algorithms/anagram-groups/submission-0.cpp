class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mpp;

        for(auto it : strs)
        {
            string str = it;
            sort(str.begin(),str.end());
            mpp[str].push_back(it);

        }

        vector<vector<string>>ans;

        for(auto iter : mpp)
        {
            ans.push_back(iter.second);
        }

        return ans;
    }
};