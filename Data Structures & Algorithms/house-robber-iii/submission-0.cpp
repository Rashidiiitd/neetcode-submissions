struct RobResult {
    int rob;
    int notRob;
};

class Solution {
public:
    RobResult dfs(TreeNode* root) {
        // Base case: null node returns 0 for both options
        if (root == nullptr) return {0, 0};

        RobResult left = dfs(root->left);
        RobResult right = dfs(root->right);

        // 1. If we rob this node, we CANNOT rob its children
        int rob = root->val + left.notRob + right.notRob;

        // 2. If we DON'T rob this node, we take the max possible from children
        // (We could choose to rob the child OR not rob the child)
        int notRob = max(left.rob, left.notRob) + max(right.rob, right.notRob);

        return {rob, notRob};
    }

    int rob(TreeNode* root) {
        RobResult result = dfs(root);
        return max(result.rob, result.notRob);
    }
};
