class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        int size = nums.size();
        int ans = 0;

        for(int mask = 0;mask<(1<<size);mask++)
        {
            int curr = 0;
            for(int i = 0;i<size;i++)
            {
                if(mask&(1<<i))
                {
                   curr ^= nums[i];
                }
            }
            ans += curr;
        }

        return ans;
    }
};