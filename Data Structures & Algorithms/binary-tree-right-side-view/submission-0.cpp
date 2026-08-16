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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        std::vector<int> nodes;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int level_size = q.size();
            TreeNode* right{};
            for(int i{}; i < level_size; ++i) {
                right = q.front();
                q.pop();
                if(right->left) {
                    q.push(right->left);
                }
                if(right->right) {
                    q.push(right->right);
                }
            }
            if(right) {
                nodes.push_back(right->val);
            }
        }
        return nodes;
    }
};
