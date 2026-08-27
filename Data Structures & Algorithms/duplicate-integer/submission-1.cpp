class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int>st;
        for(auto it : nums)
        {
            st.insert(it);
        }
        return st.size() != nums.size();
    }
};