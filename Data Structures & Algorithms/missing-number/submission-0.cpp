class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        int mask = 0;

        for(int i = 1;i<=n;i++)
        {
            mask = mask^i;
            mask = mask^(nums[i-1]);
        }

        return mask;
    }
};
