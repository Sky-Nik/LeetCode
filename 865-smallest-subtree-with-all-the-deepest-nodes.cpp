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

    void depth(unordered_map<TreeNode*, int>& depth_, TreeNode* root) {
      if (!root) {
        depth_[root] = 0;
        return;
      }
      if (!root->left && !root->right)
        depth_[root] = 1;
      depth(depth_, root->left);
      depth(depth_, root->right);
      depth_[root] = 1 + max(depth_[root->left], depth_[root->right]);
    }
  
    TreeNode* subtreeWithAllDeepest(TreeNode* root, bool initial = true) {
      if (initial) {
        depth_.clear();
        depth(depth_, root);
      }
      if (depth_[root->left] == depth_[root->right])
        return root;
      if (depth_[root->left] < depth_[root->right])
        return subtreeWithAllDeepest(root->right, false);
       return subtreeWithAllDeepest(root->left, false);
    }
};
