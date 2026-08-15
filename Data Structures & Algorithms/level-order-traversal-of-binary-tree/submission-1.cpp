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
    using LevelVec = std::vector<std::vector<int>>;

    vector<vector<int>> levelOrder(TreeNode* root) {
        LevelVec res;
        dfs(root, 1, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int curr_level, LevelVec& res) {
        if(!node) {
            return;
        }
        if (res.size() < curr_level) {
            res.push_back({});
        }
        auto& level{res[curr_level - 1]};
        level.push_back(node->val);
        dfs(node->left, curr_level + 1, res);
        dfs(node->right, curr_level + 1, res);
    }
};
