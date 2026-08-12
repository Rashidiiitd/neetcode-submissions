class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left = 0;
        // int right = 0;

        int ans = 0;
        int arr[26] = {0};
        int maxFreq = 0;

        for(int right = 0;right<s.size();right++)
        {
           arr[s[right]-'A']++;

           maxFreq = max(maxFreq,arr[s[right]-'A']);

           int len = right-left+1;
           if(len-maxFreq>k)
           {
                if(arr[s[left]-'A'] == maxFreq )
                {
                    maxFreq--;
                }
                 arr[s[left]-'A']--;
                 left++;

           }
          len = right-left+1;
          ans = max(ans,len);

        }
        // delete arr;
        return ans;
    }
};
