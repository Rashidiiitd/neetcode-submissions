class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
 int longest = 0;
        for(auto it : st){
            if(st.find(it-1)==st.end()) // matlab ye start point ho sakta hai.
            {
                int cnt = 1;
                int x  = it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                longest = max(longest,cnt);
            }
        }

        return longest;
    }
};