class Solution {
public:
    int jump(vector<int>& nums) {
        
        for(int i = 1;i<nums.size();i++)
        {
            nums[i] = max(i+nums[i],nums[i-1]);
        }

        int idx = 0;
        int jump = 0;

        while(idx<nums.size()-1)
        {
            jump++;
            idx = nums[idx];
        }

        return jump;
    }
};
