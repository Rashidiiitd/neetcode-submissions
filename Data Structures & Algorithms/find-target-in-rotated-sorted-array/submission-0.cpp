class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size()-1;
        int index = -1;
        int mid = 0;

        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid] == target) return mid;

            if(nums[left]<=nums[mid])
            {
                // means left part sorted h
                if(nums[left]<=target && target<= nums[mid])
                {
                    right = mid-1;
                }
                else 
                {
                    left = mid+1;
                }
            }
            else
            {
                                // means right part sorted h
                if(nums[mid]<=target && target<= nums[right])
                {
                    left = mid+1;
                }
                else 
                {
                    right = mid-1;
                }
            }
        }
        return index;
    }
};