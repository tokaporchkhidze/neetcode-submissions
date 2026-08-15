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
        if (!root) {
            return {};
        }
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> res;
        q.push(root);
        while(!q.empty()) {
            int level_size = q.size();
            std::vector<int> level;
            level.reserve(level_size);
            for(int i{}; i < level_size; i++) {
                auto curr{q.front()};
                level.push_back(curr->val);
                q.pop();
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            res.emplace_back(std::move(level));
        }
        return res;
    }
};
