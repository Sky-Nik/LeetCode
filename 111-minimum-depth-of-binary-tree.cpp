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
    int minDepth(TreeNode* root, bool is_root = true) {
      if (!root) return is_root ? 0 : std::numeric_limits<int>::max();
      return (root->left || root->right) ? 1 + std::min(minDepth(root->left, false), minDepth(root->right, false)) : 1; 
    }
};
