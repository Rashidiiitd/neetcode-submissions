class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;

        int current = 0;

        for(auto it : nums)
        {            
            current += it;
            sum = max(sum,current);
            if(current<0)
            { 
                current = 0;
            }
        }

        return sum;

    }
};