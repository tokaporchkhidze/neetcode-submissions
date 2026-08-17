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
 #include <ranges>
#include <span>

class Solution
{
public:
  TreeNode *buildTree(std::vector<int> &preorder,
                      std::vector<int> const &inorder)
  {
    std::unordered_map<int, int> node_index_map{};
    for (int i{}; auto val: inorder) {
      node_index_map[val] = i++;
    }
    int preorder_index = 0;
    return dfs(std::ranges::views::all(preorder), preorder_index, 0, inorder.size() - 1, node_index_map);
  }

  TreeNode *dfs(std::span<int> const preorder,
                int& preorder_index,
                int const left_bound,
                int const right_bound,
                std::unordered_map<int, int> &node_index_map)
  {
    if (left_bound > right_bound) {
      return nullptr;
    }
    auto const val = preorder[preorder_index++];
    TreeNode *node = new TreeNode(val);
    auto const inorder_index = node_index_map[val];
    node->left = dfs(preorder,
                     preorder_index,
                     left_bound,
                     inorder_index - 1,
                     node_index_map);
    node->right = dfs(preorder,
                      preorder_index,
                      inorder_index + 1,
                      right_bound,
                      node_index_map);
    return node;
  }
};
