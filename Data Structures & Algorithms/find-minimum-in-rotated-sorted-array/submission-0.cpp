class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int mini  = 100000;
        int low = 0;
        int high = nums.size()-1;
        int mid;

        while(low<=high)
        {
            mid = low + (high-low)/2;
            
            if(nums[low]<=nums[mid])
            {
                // left part is sorted 
                mini = min(mini,nums[low]);
                low = mid+1;
            }
            else
            {
                mini = min(mini,nums[mid]);
                high = mid-1;
            }
        }

        return mini;
    }
};