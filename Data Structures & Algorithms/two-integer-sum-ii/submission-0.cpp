class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int>mpp;
        mpp[nums[0]] = 0;
        for(int i = 1;i<nums.size();i++)
        {
            int req = target - nums[i];
            if(mpp.find(req)!=mpp.end())
            {
                return {mpp[req]+1,i+1};
            }

            mpp[nums[i]] = i;
        }

        return {-1,-1};
    }
};
