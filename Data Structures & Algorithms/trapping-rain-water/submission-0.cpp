class Solution { 
public: 
    int trap(vector<int>& nums) { 
        int n = nums.size(); 
        if (n <= 1) return 0; 
        
        vector<int> leftMax(n); 
        vector<int> rightMax(n); 
        
        leftMax[0] = nums[0]; 
        for(int i = 1; i < n; i++) { 
            leftMax[i] = max(leftMax[i-1], nums[i]); 
        } 
        
        rightMax[n-1] = nums[n-1]; 
        for(int i = n-2; i >= 0; i--) { 
            rightMax[i] = max(rightMax[i+1], nums[i]); 
        } 
        
        int ans = 0; 
        for(int i = 0; i < n; i++) { 
            ans = ans + min(leftMax[i], rightMax[i]) - nums[i]; 
        } 
        
        return ans; 
    } 
};
