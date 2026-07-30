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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        post_order_dfs(root, diameter);
        return diameter;
    }

    int post_order_dfs(TreeNode* node, int& diameter) {
        if (!node) {
            return 0;
        }
        auto left{post_order_dfs(node->left, diameter)};
        auto right{post_order_dfs(node->right, diameter)};
        auto curr{left + right};
        diameter = std::max(diameter, curr);
        return 1 + std::max(left, right);
    }
};
