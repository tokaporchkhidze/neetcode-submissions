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
    bool isBalanced(TreeNode* root) {
        bool res{true};
        post_order_dfs(root, res);
        return res;
    }
    
    int post_order_dfs(TreeNode* node, bool& res) {
        if (!node || !res) {
            return 0;
        }
        auto left{post_order_dfs(node->left, res)};
        auto right{post_order_dfs(node->right, res)};
        if (std::abs(left - right) > 1) {
            res = false;
        }
        return 1 + std::max(left, right);
    }
};
