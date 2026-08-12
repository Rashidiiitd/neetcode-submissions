class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char,int>mpp;

        int left = 0;
        int right = 0;

        int n = s.size();
        int ans = 0;

        while(right<n)
        {
            if(mpp.count(s[right]) )
            {
                left = max(left,mpp[s[right]]+1);

            }
                
             ans = max(ans,right-left+1);

            mpp[s[right]] = right;

            right++;
        }

        return ans;
    }
};
