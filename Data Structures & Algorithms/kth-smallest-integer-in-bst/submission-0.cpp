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
    int kthSmallest(TreeNode* root, int k) {
        int min = std::numeric_limits<int>::min();
        int count{};
        dfs(root, count, min, k);
        return min;   
    }

    void dfs(TreeNode* root, int& count, int& min, int k) {
        if(!root || count == k) {
            return;
        }
        dfs(root->left, count, min, k);
        if(count == k) {
            return;
        }
        min = root->val;
        count++;
        dfs(root->right, count, min, k);
    }
};
