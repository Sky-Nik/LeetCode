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
    unordered_map<TreeNode*, int> depth_;
  
    void depth(TreeNode* root) {
      if (!root) {
        depth_[root] = 0;
        return;
      }
      depth(root->left);
      depth(root->right);
      depth_[root] = 1 + max(depth_[root->left], depth_[root->right]);
    }
  
    bool isBalanced(TreeNode* root, bool initial = true) {
      if (initial) {
        depth_.clear();
        depth(root);
      }
      if (!root)
        return true;
      return abs(depth_[root->left] - depth_[root->right]) <= 1 &&
        isBalanced(root->left, false) && isBalanced(root->right, false);
    }
};
