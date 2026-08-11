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

    bool is_identical(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) {
            return true;
        }
        if((t1 && t2) && t1->val == t2->val) {
            return is_identical(t1->left, t2->left) && is_identical(t1->right, t2->right);
        } else {
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) {
            return false;
        }
        std::queue<TreeNode*> traversal;
        traversal.push(root);

        while(!traversal.empty()) {
            auto level_size = traversal.size();
            for(auto i{0}; i < level_size; i++) {
                auto curr_node{traversal.front()};
                traversal.pop();
                if (curr_node->val == subRoot->val) {
                    if (is_identical(curr_node, subRoot)) {
                        return true;
                    }
                }
                if(curr_node->left) {
                    traversal.push(curr_node->left);
                }
                
                if(curr_node->right) {
                    traversal.push(curr_node->right);
                }
            }
        }
        return false;
    }
};
