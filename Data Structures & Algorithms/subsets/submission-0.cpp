class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         int size = nums.size();
      vector<vector<int>>ans;

        for(int mask = 0;mask<(1<<size);mask++)
        {
            vector<int>curr;
            for(int i = 0;i<size;i++)
            {
                if(mask&(1<<i))
                {
                   curr.push_back(nums[i]);
                }
            }
           ans.push_back(curr);
        }

        return ans;
    }
};

