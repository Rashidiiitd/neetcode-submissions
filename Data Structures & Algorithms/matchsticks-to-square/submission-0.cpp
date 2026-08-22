class Solution {
public:
bool dfs(vector<int>& nums, vector<bool>& visited, int target, int currSum, int idx, int k) {
        if (k == 1) return true;

        if (currSum == target) {
            return dfs(nums, visited, target, 0, 0, k - 1); 
        }

        for (int i = idx; i < nums.size(); i++) {
            if (visited[i] || currSum + nums[i] > target) continue;

            visited[i] = true; 
            
            if (dfs(nums, visited, target, currSum + nums[i], i + 1, k)) {
                return true;
            }
            
            visited[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;

        int partitionSum = totalSum / k;
        
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > partitionSum) return false;

        vector<bool> visited(nums.size(), false);
        return dfs(nums, visited, partitionSum, 0, 0, k);
    }
    bool makesquare(vector<int>& matchsticks) {
        return canPartitionKSubsets(matchsticks,4);
    }
};