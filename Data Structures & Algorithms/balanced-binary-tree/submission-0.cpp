class Solution {
private:

    pair<bool, int> checkBalance(TreeNode* node) {
        if (node == nullptr) {
            return {true, 0};
        }

        auto left = checkBalance(node->left);
        auto right = checkBalance(node->right);

        if (!left.first || !right.first) {
            return {false, 0}; 
        }

        if (abs(left.second - right.second) > 1) {
            return {false, 0};
        }

        return {true, 1 + max(left.second, right.second)};
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
};
