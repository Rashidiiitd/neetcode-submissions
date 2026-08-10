class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        
        stack<int>st;
        vector<int>ans(tmp.size(),0);
        for(int i = tmp.size()-1;i>=0;i--)
        {
            // Remove the smaller elements from the current one
            while(!st.empty() && tmp[st.top()]<=tmp[i])
            {
                st.pop();
            }
            
            ans[i] = st.empty()?0:st.top()-i;
            st.push(i);
        }
        return ans;
    }
};