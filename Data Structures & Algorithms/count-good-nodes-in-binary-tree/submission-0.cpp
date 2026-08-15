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
    int count(TreeNode* root, int prevMax)
    {
        if(root == nullptr ) return 0;
         bool isFound = false;
        if(root->val>=prevMax)
        {
            prevMax = root->val;
            isFound = true;

        }

        int left = count(root->left,prevMax);
        int right = count(root->right,prevMax);

        if(isFound)
        {
            return 1+ left+right;
        }

        return left+right;
    }
    int goodNodes(TreeNode* root) {
        
        int prevMax = root->val;
        return count(root,prevMax);
    }
};
