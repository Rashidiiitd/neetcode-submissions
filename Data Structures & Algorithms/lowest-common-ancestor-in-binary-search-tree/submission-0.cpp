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

    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr) return nullptr;
        if(root == p || root  == q)
        {
            return root;
        }

        TreeNode* left = dfs(root->left,p,q);
        TreeNode* right = dfs(root->right,p,q);

        if(left&&right)
        {
            return root;
        }


        if(left)
        {
            return left;
        }

        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return dfs(root,p,q);
    }
};
