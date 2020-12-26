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
    std::vector<int> inorderTraversal(TreeNode* root) {
      if (!root) return {};
      auto left_traversal = inorderTraversal(root->left);
      auto right_traversal = inorderTraversal(root->right);
      left_traversal.push_back(root->val);
      std::copy(right_traversal.begin(), right_traversal.end(), std::back_inserter(left_traversal));
      return left_traversal;
    }
};
