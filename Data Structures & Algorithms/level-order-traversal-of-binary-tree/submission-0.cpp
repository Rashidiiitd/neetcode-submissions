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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if ( root == nullptr ) return {};
        
        vector<vector<int>>ans;

        queue<TreeNode*>que;

        que.push(root);

        while(que.size()>0)
        {
            int currLevelSize = que.size();
            vector<int>currLevel;
            for(int i=1;i<=currLevelSize;i++)
            {
                TreeNode *currNode = que.front();
                que.pop();
                if(currNode->left) { que.push(currNode->left);}
                if(currNode->right) {que.push(currNode->right);}
                currLevel.push_back(currNode->val);
            }
            ans.push_back(currLevel);
        }
        return ans;
    }
};