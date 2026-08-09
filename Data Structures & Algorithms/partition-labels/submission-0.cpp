class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char,int>mpp;
        for(int i = 0;i<s.size();i++)
        {
          mpp[s[i]] = i;
        }
        vector<int>ans;
        int currRange = 0;
        for(int i = 0;i<s.size();i++)
        {
            int initialRange = mpp[s[i]];
            for(int j = 0;j<initialRange;j++)
            {
                initialRange = max(initialRange,mpp[s[j]]);
            }
            int len = initialRange-i+1;
            ans.push_back(len);

            i += (len-1);
        }

        return ans;
    }
};
