class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        
        // Step 1: Mark every val in nums as -1
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
                nums[i] = -1;
            }
        }
        
        // Step 2: Move non -1 elements to the front (pushing -1 to the end)
        int k = 0; 
        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                swap(nums[k], nums[i]);
                k++;
            }
        }
        
        return k;
    }
};
