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
    TreeNode* increasingBST(TreeNode* root) {
      if (!root)
        return nullptr;
      auto new_left_root = increasingBST(root->left), new_right_root = increasingBST(root->right);
      if (new_left_root) {
        auto node = new_left_root;
        while (node->right)
          node = node->right;
        node->right = root;
        root->left = nullptr;
        root->right = new_right_root;
        return new_left_root;
      } else {
        root->right = new_right_root;
        return root;
      }
    }
};
