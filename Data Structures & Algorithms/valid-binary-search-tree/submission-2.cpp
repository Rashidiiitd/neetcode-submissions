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
   bool Checker(TreeNode* root,int l,int r)
   {
    if(root == nullptr ) return true;

    if(root->val <= l || root->val >= r) return false;

    bool left = Checker(root->left,l,root->val);
    bool right = Checker(root->right,root->val,r);


    return left && right;




   }
    bool isValidBST(TreeNode* root) {
        
        return Checker(root,INT_MIN,INT_MAX);

    }
};
