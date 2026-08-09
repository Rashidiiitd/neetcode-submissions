class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;

        int n = nums.size()-1;

        if(n == 0) return true;

        for(int i= 0;i<n;i++)
        { 
            // if(nums[i] == 0 && maxIndex  <= i) return false;
            if(i>maxIndex) return false;
            maxIndex = max(maxIndex,i+nums[i]);
            if(maxIndex >= n) return true;
        }

        return false;
    }
};