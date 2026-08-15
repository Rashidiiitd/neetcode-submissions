/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maximumSum = INT_MIN;

    int dfs(TreeNode* root)
    {
        if( root == nullptr ) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftMax = max(left,0);
        int rightMax = max(right,0);
        
        maximumSum = max(maximumSum,root->val + leftMax + rightMax);

        return max(root->val+leftMax,root->val+rightMax);
    
    }
    int maxPathSum(TreeNode* root) {
        
        dfs(root);

        return maximumSum;
    }
};