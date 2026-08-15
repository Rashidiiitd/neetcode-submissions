#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    map<int, int> mpp;

    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int &idx, int l, int r)
    {
        if (l > r) return nullptr;

        TreeNode* treeRoot = new TreeNode(preorder[idx]);

        int currRootIdx = idx;
        idx++; 
        
        treeRoot->left = builder(preorder, inorder, idx, l, mpp[preorder[currRootIdx]] - 1);
        treeRoot->right = builder(preorder, inorder, idx, mpp[preorder[currRootIdx]] + 1, r);

        return treeRoot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        int idx = 0; 
        return builder(preorder, inorder, idx, 0, inorder.size() - 1);
    }
};
