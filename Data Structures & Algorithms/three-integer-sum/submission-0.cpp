class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
     sort(nums.begin(),nums.end());
     for(int i = 0;i<nums.size();i++){
        if(i!=0 && nums[i]==nums[i-1]) continue;

        int left = i+1;
        int right = nums.size()-1;
        // vector<int>currAns
        while(left<right){
            if(nums[i] + nums[left] + nums[right] == 0){
                 vector<int>currAns;
                currAns.push_back(nums[i]);
                 currAns.push_back(nums[left]);
                  currAns.push_back(nums[right]);
                  ans.push_back(currAns);
                  while(left<right && nums[left] == nums[left+1] ) left++;
                  while(left<right && nums[right] == nums[right-1] ) right--;
                  left++;
                  right--;

            }
            else if(nums[i] + nums[left] + nums[right] < 0){
                left++;
            }
            else {
                right--;
            }

        }

     }
     return ans;



    }
};