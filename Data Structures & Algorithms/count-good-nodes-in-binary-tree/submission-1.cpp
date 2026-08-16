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
    int goodNodes(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int res{};
        dfs(root, std::numeric_limits<int>::min(), res);
        return res;
    }

    void dfs(TreeNode* root, int max, int& res) {
        if(!root) {
            return;
        }
        if (root->val >= max) {
            ++res;
        }
        dfs(root->left, std::max(max, root->val), res);
        dfs(root->right, std::max(max, root->val), res);
    }
};
