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
    std::vector<int> getLeafSequence(TreeNode* root) {
      if (!root) return {};
      if (!root->left && !root->right) { // it's a leaf
        return {root->val};
      }
      auto left_leaf_sequence = getLeafSequence(root->left),
           right_leaf_sequence = getLeafSequence(root->right);
      std::copy(right_leaf_sequence.begin(), right_leaf_sequence.end(), std::back_inserter(left_leaf_sequence));
      return left_leaf_sequence;
    }
  
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
      return getLeafSequence(root1) == getLeafSequence(root2);
    }
};
