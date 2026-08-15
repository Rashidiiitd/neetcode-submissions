class Solution {
public:
    int Inorder(TreeNode* root, int &k) {
        if (root == nullptr) return -1;

        int left_res = Inorder(root->left, k);
        
        if (left_res != -1) return left_res;

        k--;
        if (k == 0) return root->val;

        return Inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return Inorder(root, k);
    }
};
