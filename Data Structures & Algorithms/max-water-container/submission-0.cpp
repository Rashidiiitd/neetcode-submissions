class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int ans = 0;

        int low = 0;
        int high = heights.size()-1;

        while(low<high)
        {
            int width = (high-low)*min(heights[low],heights[high]);
            ans = max(ans,width);

            if(heights[low]<heights[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return ans;
    }
};
